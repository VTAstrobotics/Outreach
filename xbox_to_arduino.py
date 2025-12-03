import pygame
import serial
import time

# --------------------------------------------------------------------------
# This script connects to an arduino and sends motor speed commands
# based on input from an Xbox controller.
# to run this, use the terminal and type: python -u xbox_to_arduino.py
# Connect to Arduino (update COM port! The COM port is based on your system)
# --------------------------------------------------------------------------
arduino = serial.Serial('COM8', 115200, timeout=1)
time.sleep(2)

pygame.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

print("before the loop\n")

while True:
    pygame.event.pump()
    forward = -joystick.get_axis(1)   # Left stick Y (invert so up = forward)
    turn = joystick.get_axis(0)       # Left stick X

    # Scale to -255..255
    left_speed = int((forward - turn) * 255)
    right_speed = int((forward + turn) * 255)

    message = f"{left_speed},{right_speed}\n"
    #arduino.write(message.encode())
    print("Sending:", message.strip())
    