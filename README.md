# Moving Car V2.0
#### ARM
#### Author: Team 1
- #### Members:
    - Ahmed Hesham
    - Alaa Hisham
    - Hossam Elwahsh
    - Sarah Mohamed

## Brief
> Suppose you have a four-driving wheel robot, design the system so that the car moves in a rectangular shape.

## Quick Links
- `Video` 👉 [Youtube]()
- `Project Hex` 👉 []()
- `Documentation` 👉 [Google Docs]() 👉 [PDF]()
- `Team Backlog / Test Protocol` 👉 [Google Sheets]() 👉 [Excel]() 

----
## Requirements
### Car Components
1. Use Sprints Kit with TivaC launch pad plugged in
2. You will develop your application on the ARM microcontroller
3. Four motors (M1, M2, M3, M4)
4. One button to start (PB1)
5. One button for stop (PB2)
6. Four LEDs (LED1, LED2, LED3, LED4)
### System Requirements
1. The car starts initially from 0 speed
2. When PB1  is pressed, the car will move forward after 1 second
3. The car will move forward to create the longest side of the rectangle for 3 seconds with 50% of its maximum speed
4. After finishing the first longest side the car will stop for 0.5 seconds, rotate 90 degrees to the right, and stop for 0.5 second
5. The car will move to create the short side of the rectangle at 30% of its speed for 2 seconds
6. After finishing the shortest side, the car will stop for 0.5 seconds, rotate 90 degrees to the right, and stop for 0.5 second
7. Steps 3 to 6 will be repeated infinitely until you press the stop button (PB2)
8. PB2 acts as a sudden break, and it has the highest priority
9. LEDs Operations
    1. LED1: On means moving forward on the long side
    2. LED2: On means moving forward on the short side
    3. LED3: On means stop
    4. LED4: On means Rotating
