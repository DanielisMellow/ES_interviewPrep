from selenium import webdriver
import time

url = "https://www.google.com/"
driver = webdriver.Chrome()
# driver.maximize_window()
driver.get(url)
messageField = driver.find_element(
    "xpath", "/html/body/div[1]/div[3]/form/div[1]/div[1]/div[1]/div/div[2]/input"
)
messageField.send_keys("Lizard King")
showMessageButton = driver.find_element(
    "xpath", "/html/body/div[1]/div[3]/form/div[1]/div[1]/div[4]/center/input[1]"
)
showMessageButton.click()
time.sleep(100)
driver.close()
