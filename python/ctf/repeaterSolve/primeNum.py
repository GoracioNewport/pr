import pyautogui as pg
import time

pg.alert("Ready?")

for i in range(1998):
    pg.rightClick(795, 975)
    time.sleep(.50)
    pg.moveTo(821, 805)
    time.sleep(.30)
    pg.leftClick()
    time.sleep(.50)
    pg.leftClick(800, 1020)
    time.sleep(.50)
    pg.hotkey('ctrl', 'v')
    time.sleep(.50)
    pg.press('enter')
    time.sleep(.750)