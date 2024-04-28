import React from 'react';
import { render, act } from '@testing-library/react';
import InactivityDetector from './InactivityDetector'; // Replace with your component path

jest.mock('react', () => ({
  ...jest.requireActual('react'),
  useState: jest.fn(),
  useEffect: jest.fn(),
}));

// Mock AppUtil functions
jest.mock('./AppUtil', () => ({
  doLogout: jest.fn(),
  doRefresh: jest.fn(),
}));

describe('InactivityDetector component', () => {
  let mockSetLastActiveTime;
  let mockSetIsInactiveModalPopUpOpen;
  let mockSetSessionStartTime;

  beforeEach(() => {
    mockSetLastActiveTime = jest.fn();
    mockSetIsInactiveModalPopUpOpen = jest.fn();
    mockSetSessionStartTime = jest.fn();

    // Mock useState for all state variables
    React.useState.mockReturnValueOnce([new Date(), mockSetLastActiveTime]);
    React.useState.mockReturnValueOnce([false, mockSetIsInactiveModalPopUpOpen]);
    React.useState.mockReturnValueOnce([new Date(), mockSetSessionStartTime]);

    // Mock useEffect with empty callback for cleanup
    React.useEffect.mockImplementation((callback, deps) => {
      return () => {};
    });
  });

  it('should render without crashing', () => {
    render(<InactivityDetector />);
  });

  // Test cases from previous responses

  // Additional test cases for comprehensive coverage:
  it('should refresh session after reaching session timeout (while active)', () => {
    const { getByTestId } = render(<InactivityDetector />);

    // Simulate activity to avoid inactivity modal
    act(() => {
      jest.advanceTimersByTime(24 * 60 * 1000); // Just before inactivity threshold
      document.dispatchEvent(new Event('mousemove'));
    })

    // Simulate session timeout
    act(() => jest.advanceTimersByTime(4 * 60 * 1000)); // Reach session timeout

    expect(AppUtil.doRefresh).toHaveBeenCalled();
    expect(mockSetSessionStartTime).toHaveBeenCalled();
  });


  it('should not display the inactivity modal if user is active', () => {
    const { queryByText } = render(<InactivityDetector />);

    act(() => jest.advanceTimersByTime(25 * 60 * 1000)); // Below inactivity threshold

    expect(queryByText('You\'ve been inactive for a while')).not.toBeInTheDocument();
  });

  it('should close the inactivity modal if user interacts within timeout', () => {
    const { getByText, getByTestId } = render(<InactivityDetector />);

    // Simulate inactivity
    act(() => jest.advanceTimersByTime(27 * 60 * 1000));

    expect(getByText('You\'ve been inactive for a while')).toBeInTheDocument();

    const continueButton = getByTestId('continueSessionButton');
    act(() => continueButton.click());

    expect(mockSetIsInactiveModalPopUpOpen).toHaveBeenCalledWith(false);
  });

  it('should not logout if user interacts with the modal within timeout (logout button)', () => {
    const { getByTestId } = render(<InactivityDetector />);

    // Simulate inactivity
    act(() => jest.advanceTimersByTime(27 * 60 * 1000));

    const logoutButton = getByTestId('logoutButton');

    // Simulate user interaction within timeout
    act(() => logoutButton.click());

    expect(AppUtil.doLogout).not.toHaveBeenCalled();
  });

  it('should trigger logout after session timeout (while inactive)', () => {
    render(<InactivityDetector />);

    // Simulate inactivity for a long duration
    act(() => jest.advanceTimersByTime(30 * 60 * 1000)); // Exceed session timeout

    expect(AppUtil.doLogout).toHaveBeenCalled();
  });

  it('should not trigger logout after session timeout (while active)', () => {
    const { getByTestId } = render(<InactivityDetector />);

    // Simulate activity to avoid inactivity modal
    act(() => {
      jest.advanceTimersByTime(24 * 60 * 1000); // Just before inactivity threshold
      document.dispatchEvent(new Event('mousemove'));
    });

    // Simulate session timeout
    act(() => jest.advanceTimersByTime(4 * 60 * 1000)); // Reach session timeout

    expect(AppUtil.doLogout).not.toHaveBeenCalled();
  });

  it('should set last active time on continue session click', () => {
    render(<InactivityDetector />);

    act(() => mockSetLastActiveTime.mockReturnValueOnce(new Date()));

    expect(mockSetLastActiveTime).toHaveBeenCalledTimes(1); // Initial state
  });

  it('should set session start time on continue session click', () => {
    render(<InactivityDetector />);

    act(() => mockSetSessionStartTime.mockReturnValue
