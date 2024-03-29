# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [ {'description': 'PINA: 0x01 => PORTB: 0x00,PORTC: 0x10',
    'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 1 } ],
    'expected': [('PORTC',0x10),('PORTB',0x00)]
    },
    {'description': 'PINA: 0x10 => PORTB: 0x01,PORTC: 0x00',
    'steps': [ {'inputs': [('PINA',0x10)], 'iterations': 1 } ],
    'expected': [('PORTC',0x00),('PORTB',0x01)]
    },
    {'description': 'PINA: 0xE3 => PORTB: 0x0E,PORTC: 0x30',
    'steps': [ {'inputs': [('PINA',0xE3)], 'iterations': 1 } ],
    'expected': [('PORTC',0x30),('PORTB',0x0E)]
    },
    {'description': 'PINA: 0x3E => PORTB: 0x03,PORTC: 0xE0',
    'steps': [ {'inputs': [('PINA',0x3E)], 'iterations': 1 } ],
    'expected': [('PORTC',0xE0),('PORTB',0x03)]
    },
    {'description': 'PINA: 0xFF => PORTB: 0x0F,PORTC: 0xF0',
    'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 1 } ],
    'expected': [('PORTC',0xF0),('PORTB',0x0F)]
    },
    
]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
#watch = ['<function>::<static-var>','PORTB']

