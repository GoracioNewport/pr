from telegram.ext import *
import time
import requests

import telegramBot.config
import telegramBot.responses

import common
import config

prefix = "[TELEGRAM API]"

latestMessageLocal = {}
messageCooldown = 60

def startCommand(update, context):
	update.message.reply_text("Привет! 😊 Меня зовут OHS, и Я прослежу за состоянием организма пользователя.\nПо запросу Я буду отправлять статистические данные и отображать общий уровень здоровья.\nПри крайних показателях Я напишу Вам сам, чтобы Вы поняли, что необходима проверка. 😉\nПриятного использования!")
	common.latestUser = update['message']['chat']['id']

def helpCommand(update, context):
	update.message.reply_text("Я вижу, что Вам нужна помощь. В моем каталоге есть несколько действий: \n/start - готов к работе\n/help - вспомнить функционал\n/stats - все данные о здоровье \nЭто всё, что Я могу сейчас, а ещё Я напишу Вам, если показатели будут резко менять своё значение. Надеюсь, теперь наша работа будет эффективнее!")
	common.latestUser = update['message']['chat']['id']

def handleMessage(update, context):
	print(prefix, "Message Handle: ", update, context)
	text = str(update.message.text).lower()
	response = telegramBot.responses.response(text)
	common.latestUser = update['message']['chat']['id']

	update.message.reply_text(response)

def handleError(update, context):
	print(f"Update {update} caused error {context}")
	common.latestUser = update['message']['chat']['id']

	
def sendMessage(id, dataIn):

	global latestMessageLocal

	data = { "chat_id":id }


	data['text'] = "Внимание ‼️\nЗначение " + config.literalToString[dataIn['key']] + (" выше" if dataIn['type'] == 'MAX' else " ниже") + " нормы, просьба принять необходимые меры ❗"

	if (latestMessageLocal and id == latestMessageLocal["chat_id"] and (time.time() - latestMessageLocal['time']) <= messageCooldown):
		return

	latestMessageLocal = data
	latestMessageLocal['time'] = time.time()
	requests.post("https://api.telegram.org/bot" + telegramBot.config.API_KEY + "/sendMessage", json=data)



def init():
	print(prefix, "Bot work started...")
	
	global updater
	updater = Updater(telegramBot.config.API_KEY, use_context=True)

	dp = updater.dispatcher

	dp.add_handler(CommandHandler("start", startCommand))
	dp.add_handler(CommandHandler("help", helpCommand))

	dp.add_handler(MessageHandler(Filters.text, handleMessage))

	dp.add_error_handler(handleError)

	updater.start_polling()
	updater.idle()