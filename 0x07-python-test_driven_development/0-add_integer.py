#!/usr/bin/python3
<<<<<<< HEAD
"""

This module is composed by a function that adds two numbers

"""


def add_integer(a, b=98):
    """ Function that adds two integer and/or float numbers

    Args:
        a: first number
        b: second number

    Returns:
        The addition of the two given numbers

    Raises:
        TypeError: If a or b aren't integer and/or float numbers

    """

    if not isinstance(a, int) and not isinstance(a, float):
        raise TypeError("a must be an integer")
    if not isinstance(b, int) and not isinstance(b, float):
        raise TypeError("b must be an integer")
    a = int(a)
    b = int(b)
    return (a + b)
=======
""" This a function that adds to  two integers """


def add_integer(a, b=98):
	if not isinstance(a,(int, float)):
		raise TypeError("a must be an integer")
	if not isinstance(b,(int, float)):
		raise TypeError("b must be an integer")
	if type(a) == float:
		a = int(a)
	if type(b) == float:
		b = int(b)
	return (a + b)
>>>>>>> 3806f8709cb8bfa1ea00e143a8f81e444e82abd5
