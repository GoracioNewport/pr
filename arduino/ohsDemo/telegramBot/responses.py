import api

def response(inputTest):
	userMessage = str(inputTest).lower()

	if (userMessage == '/love'):
		return "я люблю Алину"

	if (userMessage == '/stats'):
		data = api.getLatestStats()

		text = "На данный момент известны эти характеристики:\n" + \
			"Пульс — " + str(data['l']) + '\n' + \
			"Двигательная активность — " + str([data['x'], data['y'], data['z']]) + '\n' + \
			"Температура — " + str(data['t']) + '\n' + \
			"Влажность — " + str(data['h']) + '\n' + \
			"Сатурация — " + str(data['s']) + '\n'

		return text

	return "Сорян борян, Я ничего не понял... :("