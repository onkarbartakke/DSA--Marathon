import React from 'react';
import { render, act, fireEvent } from '@testing-library/react';
import InactivityDetector from './InactivityDetector'; // Assuming the component is in a file named InactivityDetector.js

jest.mock('./AppUtil', () => ({
  doLogout: jest.fn(),
  doRefresh: jest.fn(),
}));

describe('InactivityDetector component', () => {
  let mockSetLastActiveTime;
  let mockSetIsInactiveModalPopUpOpen;
  let mockSetSessionStartTime;
  let setIntervalMock;
  let clearIntervalMock;

  beforeEach(() => {
    mockSetLastActiveTime = jest.fn();
    mockSetIsInactiveModalPopUpOpen = jest.fn();
    mockSetSessionStartTime = jest.fn();
    setIntervalMock = jest.fn();
    clearIntervalMock = jest.fn();

    jest.spyOn(window, 'setInterval').mockImplementation(setIntervalMock);
    jest.spyOn(window, 'clearInterval').mockImplementation(clearIntervalMock);

    jest.spyOn(React, 'useState').mockImplementation((initialState) => [
      initialState,
      mockSetLastActiveTime,
    ]);
    jest.spyOn(React, 'useState').mockImplementationOnce((initialState) => [
      initialState,
      mockSetIsInactiveModalPopUpOpen,
    ]);
    jest.spyOn(React, 'useState').mockImplementationOnce((initialState) => [
      initialState,
      mockSetSessionStartTime,
    ]);
  });

  afterEach(() => {
    jest.clearAllMocks();
  });

  it('renders the component correctly initially', () => {
    const { getByText } = render(<InactivityDetector />);

    expect(getByText('You\'ve been inactive for a while. Your Session might timeout')).not.toBeInTheDocument();
    expect(mockSetLastActiveTime).toHaveBeenCalledTimes(1);
    expect(mockSetIsInactiveModalPopUpOpen).toHaveBeenCalledWith(false);
    expect(mockSetSessionStartTime).toHaveBeenCalledTimes(1);
  });

  it('checks inactivity and opens modal after threshold (using Jest timers)', async () => {
    const { getByText, getByTestId } = render(<InactivityDetector />);

    // Simulate initial activity
    act(() => {
      mockSetLastActiveTime(new Date());
    });

    // Advance simulated time 25 minutes (just below inactivity threshold)
    jest.advanceTimersByTime(25 * 60 * 1000);

    // Expect modal not to be open yet
    expect(getByText('You\'ve been inactive for a while. Your Session might timeout')).not.toBeInTheDocument();

    // Advance simulated time 2 minutes (past inactivity threshold)
    jest.advanceTimersByTime(2 * 60 * 1000);

    // Expect modal to be open
    expect(getByText('You\'ve been inactive for a while. Your Session might timeout')).toBeInTheDocument();
    expect(mockSetIsInactiveModalPopUpOpen).toHaveBeenCalledWith(true);
  });

  it('closes modal and refreshes session on continue button click', async () => {
    const { getByText, getByTestId } = render(<InactivityDetector />);

    // Simulate inactivity to open modal
    act(() => {
      mockSetLastActiveTime(new Date());
    });
    jest.advanceTimersByTime(27 * 60 * 1000); // Past inactivity threshold

    // Expect modal to be open
    expect(getByText('You\'ve been inactive for a while. Your Session might timeout')).toBeInTheDocument();

    // Click continue button
    fireEvent.click(getByTestId('continueSessionButton'));

    // Expect modal to be closed and session refreshed
    expect(getByText('You\'ve been inactive for a while. Your Session might timeout')).not.toBeInTheDocument();
    expect(mockSetIsInactiveModalPopUpOpen).toHaveBeenCalledWith(false);
    expect(AppUtil.doRefresh).toHaveBeenCalledTimes(1); // Mocked function
  });

  it('logs out after inactivity for additional period after modal (using Jest timers)', async () => {
    const { getByText } = render(<InactivityDetector />);

    // Simulate inactivity to open modal
    act(() => {
      mockSetLastActiveTime(new Date());
    });
    jest.advanceTimersByTime(27 * 60 * 1000); // Past inactivity threshold

    //
