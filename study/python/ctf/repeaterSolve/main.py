import pyautogui as pg
import time
import win32clipboard

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
          107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
          227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347,
          349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
          467, 479, 487, 491, 499 ]

pg.alert("Ready?")

pg.moveTo(700, 800)
pg.leftClick()

for i in range(200):
    # pg.rightClick(795, 975)
    # time.sleep(.50)
    # pg.moveTo(821, 805)
    # time.sleep(.30)
    # pg.leftClick()
    # time.sleep(.50)
    # pg.leftClick(800, 1020)
    # time.sleep(.50)
    # pg.hotkey('ctrl', 'v')
    # time.sleep(.50)
    # pg.press('enter')
    # time.sleep(.750)
    pg.moveTo(970, 580)
    pg.doubleClick()
    pg.hotkey('ctrl', 'c')

    win32clipboard.OpenClipboard()
    n = win32clipboard.GetClipboardData()
    win32clipboard.CloseClipboard()
    print(n)

    if (int(n) in primes):
        # print("Prime")
        pg.moveTo(700, 900)
        pg.leftClick()
    else:
        pg.moveTo(1200, 900)
        pg.leftClick()

    # break