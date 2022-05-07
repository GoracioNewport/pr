import api

def response(inputTest):
	userMessage = str(inputTest).lower()

	if (userMessage == '/love'):
		return "я люблю Алину"

	if (userMessage == '/stats'):
		return str(api.getLatestStats())

	return "Сорян борян, Я ничего не понял... :("