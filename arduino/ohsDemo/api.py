import telegramBot.core
import common

prefix = "[OHS API]"

def sendMessage(id, data):
	print(prefix, "SEND", id, data)
	telegramBot.core.sendMessage(id, data)

def getLatestStats():
	return common.latestData