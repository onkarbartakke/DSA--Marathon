import React from 'react';
import { render, fireEvent, waitFor, screen } from '@testing-library/react';
import '@testing-library/jest-dom/extend-expect';
import InactivityDetector from './InactivityDetector';

jest.mock('./AppUtil', () => ({
  doLogout: jest.fn(),
  doRefresh: jest.fn(),
}));

jest.useFakeTimers();

describe('InactivityDetector', () => {
  beforeEach(() => {
    render(<InactivityDetector />);
  });

  afterEach(() => {
    jest.clearAllTimers();
    jest.useRealTimers();
  });

  test('renders without crashing', () => {
    expect(screen.getByRole('presentation')).toBeInTheDocument();
  });

  test('should set isInactiveModalPopUpOpen to true after inactivity threshold', () => {
    jest.advanceTimersByTime(26 * 60 * 1000 + 1000);
    expect(screen.getByRole('dialog')).toBeInTheDocument();
    expect(screen.getByText(/You've been inactive for a while/i)).toBeInTheDocument();
  });

  test('should call doLogout after inactivity threshold + popup timeout', () => {
    const { AppUtil } = require('./AppUtil');
    jest.advanceTimersByTime(26 * 60 * 1000 + 2 * 60 * 1000 + 1000);
    expect(AppUtil.doLogout).toHaveBeenCalled();
  });

  test('should call doRefresh after session timeout', () => {
    const { AppUtil } = require('./AppUtil');
    jest.advanceTimersByTime(28 * 60 * 1000 + 1000);
    expect(AppUtil.doRefresh).toHaveBeenCalled();
  });

  test('should continue session and close modal on "Continue Session" button click', () => {
    jest.advanceTimersByTime(26 * 60 * 1000 + 1000);
    const continueButton = screen.getByTestId('continueSessionButton');
    fireEvent.click(continueButton);
    expect(screen.queryByRole('dialog')).not.toBeInTheDocument();
  });

  test('should call doLogout on "Logout" button click', () => {
    jest.advanceTimersByTime(26 * 60 * 1000 + 1000);
    const logoutButton = screen.getByTestId('logoutButton');
    fireEvent.click(logoutButton);
    const { AppUtil } = require('./AppUtil');
    expect(AppUtil.doLogout).toHaveBeenCalled();
  });

  test('should reset inactivity timer on user activity', () => {
    jest.advanceTimersByTime(26 * 60 * 1000 - 1000);
    fireEvent.mouseMove(window);
    jest.advanceTimersByTime(26 * 60 * 1000 + 1000);
    expect(screen.queryByRole('dialog')).not.toBeInTheDocument();
  });
});