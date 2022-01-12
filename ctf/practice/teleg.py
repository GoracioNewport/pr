from telegram.ext import Updater
updater = Updater(token='1223788311:AAHNfJxNFq9BguXTSPcOgFYldKIQ4h-SW2s', use_context=True)

dispatcher = updater.dispatcher

def start(update, context):
    context.bot.send_message(chat_id=update.effective_chat.id, text="I'm a bot, please talk to me!")