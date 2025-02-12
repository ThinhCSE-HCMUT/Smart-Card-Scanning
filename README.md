<p align="center">
 <h1 align="center">Smart Card Scanning</h1>
</p>

## 🏠 Introduction
This project is a **Smart Card Scanning System** designed for a **smart door access control** in my house. The system uses RFID technology to authenticate users and grant or deny access based on card data in database system. 

## 🔹 Features
- ✅ **Scan & Authenticate Smart Cards**: using RFID technology
- ✅ **Access Control**: Grant or deny entry based on stored credentials
- ✅ **Logging System**: Record successful and failed access attempts to the Web Server
- ✅ **LCD Display**: Show authentication status
- ✅ **Buzzer/LED Alerts**: Show access granted/denied
- ✅ **Storage**: Store authorized card IDs in a simple database

## 🛠️ Technologies Used
- **Microcontroller**: ESP32 and STM32
- **RFID Module**: MFRC522
- **Programming Languages**: C/C++
- **Communication Interfaces**: SPI, I2C, UART
- **Additional Components**: LCD display, Buzzer, LED RGB and a power supply system
## 📸 Demonstration
Below are images and a demo GIF showcasing the **Smart Card Scanning** system in action.  

### 🔧 Hardware Setup
The following image shows the hardware components, including the smart card scanner, microcontroller, and connected peripherals.  

<p align="center">
  <img src="Demo/hardware_image.jpg" width="600">
  <br/>
  <i>Hardware setup of the Smart Card Scanning system</i>
</p>

### 🎥 System in Action
The GIF below demonstrates how the smart card is scanned and the system responds accordingly.  

<p align="center">
  <img src="Demo/demo_project.gif" width="600">
  <br/>
  <i>Smart Card Scanning system demo</i>
</p>

This system enables **secure and efficient access control**, making it ideal for home security applications. 🚀  
## 🚀 Future Improvements
- Integration with a mobile app for remote access management
- Adding WiFi/Bluetooth for IoT connectivity
- Replacing primitive databases with modern database management systems such as SQLite, MySQL or Firebase
- Building stronger authentication mechanisms, such as combining RFID cards with PINs or biometrics (fingerprints, facial recognition)
