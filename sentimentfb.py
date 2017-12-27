#/***************************************************************************************************
#How to use the Facebook developer GraphAPI for retreiving & adding the data to the Facebook Account
#URL: http://facebook-sdk.readthedocs.io/en/latest/api.html
#***************************************************************************************************/
import facebook as fb
import numpy as np

def connect(access_token,user):
	print("Connect Entered\n")
	graph = fb.GraphAPI(access_token)
	print("Graph Not Null\n")
	if(graph == 0):
		print("Graph Null\n")
	profile = graph.get_object("me")
	
	return graph,profile
	
	
def main():
	print("Sentiment Analysis For Facebook\n");
	access_token = "EAAZAf6VxNkooBAO3w4PSm6eEfF0lHRmo57YsqjkuxJ0QijIOXoukYDES9WbcM8U1YQBVdr9EtpMHZA0vtyz3clroMbZC3MZCZAsMbQNksHW1rJkUGRf32GaW8m2unhIVeHOS0spZAkOZAWqynUgUmZBsSkrelRiy2tFPK3LlXl8536a2aKNfZAXviFiu1svUesAQZD"
	user = "manojshakti"
	
	graph,profile = connect(access_token, user)
	
	users = graph.search(type = "event",q="Christmas",limit=5000)
	#friends = graph.get_all_connections(profile['id'],"friends",limit=1000)
	#friend_list = [friend['data'] for friend in friends['data']]
	
	for user in users['data']:
		print('%s %s' % (user['id'],user['name'].encode()))

	#print(friends)
	#print(friend_list)
	
main()
