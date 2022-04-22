# InnovateFPGA-AP044
A project proposing a design model with a theme of Connecting the Edge for a Sustainable future.

The design can be run with using codes in ADC & DE10_NANO_RFS_SENSOR directories. 

Link to InnovateFPGA Project Page: https://www.innovatefpga.com/cgi-bin/innovate/teams.pl?Id=AP044&All=1

Wildfire Prevention - Way to Conserve Biodiversity

![image](https://user-images.githubusercontent.com/87360204/163711020-77a0f129-1e88-46b6-8cd2-605ba0630ce8.png)
 
Block Diagram 

 ![block](https://user-images.githubusercontent.com/87360204/163711066-0c3aa194-3ba9-4f1e-9bcf-1c4748dbc4ca.jpeg)

Functional description & Implementation

Our proposed model has 2 phases:

1. Mapping of highly probable wildfire regions:
We start with studying the nature of the forest and the factors that affect the occurrence of fire in the region. This study helps us in mapping the hotspots by computing the probability of occurrence of fire by Machine Learning models and deploying these models on Azure cloud for continuous monitoring purpose.

2. Early Detection of Wildfires:
The hotspots mapped in the previous step are our area of study where the FPGA cloud connectivity kits are placed. These kits are equipped with various sensors for measuring Temperature, Humidity, Flame detection, Gas sensors, Wind sensors for monitoring these hotspots clearly to understand the behaviour of forest fires and these sensors help in early detection of forest fire and alert the responsible authority.

![flow1](https://user-images.githubusercontent.com/87360204/163711427-736895ac-ac9d-491e-82f1-15bd071bf497.png)
 
![kit1](https://user-images.githubusercontent.com/87360204/163711474-320d0de2-5108-4fad-b2a1-cbaba31bf873.png)

![WhatsApp Image 2022-04-22 at 9 46 11 AM (1)](https://user-images.githubusercontent.com/87360204/164692161-a43e6a26-48cc-4035-bced-dc946a1a670c.jpeg)
 
fig. a) Software Flow Diagram                           fig. b) Hardware connection Diagram                           fig. 3 Smart Kit with Loom Solar panel source.                             
I. Software Flow diagram: Software part of the project is mainly focused on Predicting and Mapping the forest fire vulnerable hotspots clearly on the map. 
1. Prediction of Probability of fire occurrence in a region: The dataset consisting of the climate parameters that affect wildfires such as Temperature, Humidity, Dew Point, Wind speed, Pressure etc. are collected and are processed and divided into training and validation set to train and test the ML model.
So first the training set is divided into construction and prediction set. This will be used to train the model and to check whether the model is able to predict the required result efficiently and accurately. Several Machine Learning algorithms have been tested and performance evaluation for each algorithm is done. And based on the evaluation XGBOOST algorithm is chosen to optimize the model.
This model is then fed with the validation set data to predict the probability of fire.
2. Mapping of the highly fire prone regions. The predicted output from the previous step for the given data is used to map fire hotspots in the region using a geospatial tool. The mapping output predicts the regions where the probability of fire occurrence is greater than a particular cut off. These hotspots are our regions of study to understand the behaviour of forest fires and their behaviour towards different parameters which could vary for every forest under consideration.
The above model is deployed on Microsoft Azure Cloud for remote access of these data and continuous monitoring of data for the model considered. 
 
II. Hardware Block diagram: The DE10 Nano SoC board is the main focus in this project. The DE10 Nano provided with RFS Daughter Card which has inbuilt Wifi, Bluetooth, Sensors such as Temperature, Humidity, Accelerometer, etc. We have made use of this inbuilt sensors for Temperature, Humidity measurements as they are correlated to the fire occurrence. RFS Daughter Card is connected to DE10 Nano Board using JTAG Cable through GPIO 0 pin of the DE10 Nano Board.
We have also used IR Flame Sensor which is used to measure the presence/absence of flame in the IR range. IR Flame sensors are connected to DE10 Nano board using ADC pins where we have connected as shown in fig.b)
These sensor values are continuously processed and sent to Azure's cloud services IoT Hub where it undergoes various computations and send an Alert message in the form or HTTP or SMS services to the respective organisation or person if any thresholds are crossed.
We have used Loom solar panel to power the Smart Kit (shown in fig.c). Throughout the day, the Kit will be powered directly from the Solar panel via Voltage controller. We will charge batteries also simultaneously so that we can use them as a source during Night time.
 
Results

Temperature & Humidity Sensor Outputs: 
![sen1_1](https://user-images.githubusercontent.com/87360204/163711609-ecc90b27-adfd-4d0e-8524-76f36692fc54.jpeg)
      
Flame Sensors Outputs:
![sen2_1](https://user-images.githubusercontent.com/87360204/163711649-b8f31a74-578c-467a-9b33-922ab5a62e09.jpeg)

MAPPING OUTPUTS:
![model](https://user-images.githubusercontent.com/87360204/163711214-d6b44990-ca48-4bff-8540-2da5ec7b6e07.jpeg)

![Screenshot (578)](https://user-images.githubusercontent.com/87360204/163711241-20a3b064-ceda-4071-a6af-211cf2f55551.png)
   
 

             
                                                                                                                                                                 

