# Test file for Lab4_SM


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test "don't press anything => PORTB: 0x01, next_state: 1"
set next_state = LED_Start
setPINA 0x00
continue 3
expectPORTB 0x01
expect next_state 1
checkResult

# Test from init: !A0, A0 => PORTB: 0x02
test "press once => PORTB: 0x02, next_state: 2"
set next_state = LED_Start
setPINA 0x00
continue 1
setPINA 0x01
continue 1
expectPORTB 0x02
expect next_state 2
checkResult

# Test from init: !A0, A0, !A0, A0 => PORTB: 0x01
test "press twice => PORTB: 0x01, next_state: 1"
set next_state = LED_Start
setPINA 0x00
continue 1
setPINA 0x01
continue 1
setPINA 0x00
continue 1
setPINA 0x01
continue 1
expectPORTB 0x01
expect next_state 1
checkResult

test "press 5 times => PORTB: 0x02, next_state: 1"
set next_state = LED_Start
setPINA 0x00
continue 1
setPINA 0x01
continue 1
setPINA 0x00
continue 1
setPINA 0x01
continue 1
setPINA 0x00
continue 1
setPINA 0x01
continue 1
setPINA 0x00
continue 1
setPINA 0x01
continue 1
setPINA 0x00
continue 1
setPINA 0x01
continue 1
expectPORTB 0x02
expect next_state 2
checkResult

test "press once, button let go => PORTB: 0x02, next_state: 1"
set next_state = LED_Start
setPINA 0x00
continue 1
setPINA 0x01
continue 1
setPINA 0x00
continue 4
expectPORTB 0x02
expect next_state 2
checkResult


# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
