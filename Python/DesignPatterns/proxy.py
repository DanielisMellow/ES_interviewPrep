import time

class Producer:
	"""Define the 'resource-intensive' object to instantiate!"""
	def produce(self):
		print("Producer is working hard!")

	def meet(self):
		print("Producer has time to meet you now!")

# Proxy Handles all the request from the guest 
class Proxy:
	""""Define the 'relatively less resource-intensive' proxy to instantiate as a middleman"""
	def __init__(self):  
		self.occupied = 'No'
		self.producer = None

	def produce(self):
		"""Check if Producer is available"""
		print("Artist checking if Producer is available ...")

		if self.occupied == 'No':
			#If the producer is available, create a producer object!
			self.producer = Producer()
			time.sleep(2)

			#Make the prodcuer meet the guest!
			self.producer.meet()
			
		else:
			#Otherwise, don't instantiate a producer 
			time.sleep(2)
			print("Producer is busy!")

#Instantiate a Proxy
p = Proxy()

#Make the proxy: Artist produce until Producer is available
p.produce()

#Change the state to 'occupied'
p.occupied = 'No'

#Make the Producer produce
p.produce()