import pyautogui as pg
import time, numpy, win32clipboard


pg.alert("Ready?")
b = ["я", "тебя", "люблю"]


for i in range(100):

    b = numpy.random.permutation(b)
    s = " ".join(b).capitalize()

    win32clipboard.OpenClipboard()
    win32clipboard.EmptyClipboard()
    win32clipboard.SetClipboardText(s, win32clipboard.CF_UNICODETEXT)
    # time.sleep(.1)
    pg.hotkey('ctrl', 'v')
    time.sleep(.02)
    pg.press('enter')
    time.sleep(.01)
    win32clipboard.CloseClipboard()
    time.sleep(.07)

