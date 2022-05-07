import threading

import config
import common
import telegramBot.core
import dataFetch
import api


fetch = threading.Thread(target=dataFetch.init())
fetch.start()


bot = threading.Thread(target=telegramBot.core.init)
bot.start()

while True:
	data = dataFetch.read()
	common.latestData = data

	if data['ok'] and common.latestUser:

		for key, val in config.maxValues.items():
			if float(data[key]) >= float(val):
				api.sendMessage(common.latestUser, {"type":"MAX", "key":key, "val":val})

		for key, val in config.minValues.items():
			if float(data[key]) >= float(val):
				api.sendMessage(common.latestUser, {"type":"MIN", "key":key, "val":val})

dataFetch.close()