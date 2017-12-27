/***************************************************************************************************
How to use the Facebook developer GraphAPI for retreiving & adding the data to the Facebook Account
URL: http://facebook-sdk.readthedocs.io/en/latest/api.html
***************************************************************************************************/
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
	access_token = "EAAZAf6VxNkooBANMeM1W9oD2WIZB02A0Ysl1dN6iZBZCjVHKs0xSpmx9KyHeaNQiV2qTB5zfVtNYavitbwHHYJCBfSWMQYTy9LCN8IZCBZBgq4adEC5aFqwoYPavgQ3eNrTH8RZAZAp77KejtdQtBSbJhofiZC0cqtt3kuKvajWAQaCEeWFIYTi7lAEjXUQfYZAjUZD"
	user = "manojshakti"
	
	graph,profile = connect(access_token, user)
	
	friends = graph.get_connections(profile['id'],"comments",limit=1000)
	#friend_list = [friend['name'] for friend in friends['data']]

	print(friends)
	
main()
