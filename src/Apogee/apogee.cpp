#include "apogee.h"

Apogee::Apogee() {};
Apogee::~Apogee() {};

float Apogee::calculateHeight(float *matrix){};

// // apogee.cpp : This file contains the 'main' function. Program execution begins and ends there.
// //

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <fstream>
// #include <Eigen/Dense>
// #include <Eigen/Core>


// using std::vector;
// // A class for representing an altimeter sensor
// class Altimeter {
// public:
//     // Constructor
//     Altimeter() {
//         // Initialize the altitude to 0
//         altitude = 0;
//         // Initialize the index to 0
//         index = 0;
//     }

//     // Get the current altitude reading from the altimeter
//     double get_altitude() {
//         // In a real implementation, this method would get the altitude
//         // reading from the altimeter sensor. For now, we will just return
//         // the current altitude stored in the object.
//         return altitude;
//     }

//     // Set the current altitude
//     void set_altitude(double alt) {
//         altitude = alt;
//     }

//     // Read values from a file and store them in an array
//     void read_from_file(const std::string& filename) {
//         // Open the file
//         std::ifstream file(filename);

//         // Check if the file was successfully opened
//         if (!file.is_open()) {
//             // The file could not be opened
//             std::cerr << "Error: could not open file '" << filename << "'" << std::endl;
//             return;
//         }

//         // Clear the array
//         altitude_values.clear();

//         // Read the altitude values from the file and store them in the array
//         while (!file.eof()) {
//             double altitude_from_file;
//             file >> altitude_from_file;
//             altitude_values.push_back(altitude_from_file);
//         }
//     }

//     // Get the next altitude value from the array and update the index
//     double get_next_altitude() {
//         // Check if the array is empty
//         if (altitude_values.empty()) {
//             // The array is empty, so return 0
//             return 0;
//         }

//         // Get the next altitude value from the array
//         double next_altitude = altitude_values[index];

//         // Update the index
//         index = (index + 1) % altitude_values.size();

//         // Return the next altitude value
//         return next_altitude;
//     }

// private:
//     // The current altitude reading from the altimeter
//     double altitude;
//     // An array of altitude values read from a file
//     vector<double> altitude_values;
//     // The index of the next altitude value to return
//     int index;
// };

// // A class for representing a barometer sensor
// class Barometer {
// public:
//     // Constructor
//     Barometer() {
//         // Initialize the pressure to 0
//         pressure = 0;
//         // Initialize the index to 0
//         index = 0;
//     }

//     // Get the current pressure reading from the barometer
//     double get_pressure() {
//         // In a real implementation, this method would get the pressure
//         // reading from the barometer sensor. For now, we will just return
//         // the current pressure stored in the object.
//         return pressure;
//     }

//     // Set the current pressure
//     void set_pressure(double p) {
//         pressure = p;
//     }

//     // Read values from a file and store them in an array
//     void read_from_file(const std::string& filename) {
//         // Open the file
//         std::ifstream file(filename);

//         // Check if the file was successfully opened
//         if (!file.is_open()) {
//             // The file could not be opened
//             std::cerr << "Error: could not open file '" << filename << "'" << std::endl;
//             return;
//         }

//         // Clear the array
//         pressure_values.clear();

//         // Read the pressure values from the file and store them in the array
//         while (!file.eof()) {
//             double pressure_from_file;
//             file >> pressure_from_file;
//             pressure_values.push_back(pressure_from_file);
//         }
//     }

//     // Get the next pressure value from the array and update the index
//     double get_next_pressure() {
//         // Check if the array is empty
//         if (pressure_values.empty()) {
//             // The array is empty, so return 0
//             return 0;
//         }

//         // Get the next pressure value from the array
//         double next_pressure = pressure_values[index];

//         // Update the index
//         index = (index + 1) % pressure_values.size();

//         // Return the next pressure value
//         return next_pressure;
//     }

// private:
//     // The current pressure reading from the barometer
//     double pressure;
//     // An array of pressure values read from a file
//     std::vector<double> pressure_values;
//     // The index of the next pressure value to return
//     int index;
// };



// // A class for representing a Kalman filter

// // class KalmanFilter {
// // public:
// //     // Constructor
// //     KalmanFilter() {
// //         // Initialize the true altitude to 0
// //         true_altitude = 0;
// //         // Initialize the previous true altitudes
// //         prev_true_altitudes = { 0, 0, 0 };

// //         // Initialize the state transition matrix
// //         A << 1, 1,
// //             0, 1;

// //         // Initialize the measurement matrix
// //         H << 1, 0;

// //         // Initialize the process noise covariance matrix
// //         Q << 0.1, 0,
// //             0, 0.1;

// //         // Initialize the measurement noise covariance matrix
// //         R << 0.1;

// //         // Initialize the state vector
// //         x << 0, 0;

// //         // Initialize the covariance matrix
// //         P << 1, 0,
// //             0, 1;
//     }

//     // // Update the true altitude using the altitude and pressure readings from the altimeter and barometer sensors
//     // void update(double altitude, double pressure) {
//     //     // Use a kalman filter to combine the altitude and pressure readings and calculate the true altitude

//     //     // Predict the next state of the system
//     //     x = A * x;
//     //     P = A * P * A.transpose() + Q;

//     //     // Update the state estimate using the altitude reading
//     //     y = altitude - H * x;
//     //     S = H * P * H.transpose() + R;
//     //     K = P * H.transpose() * S.inverse();
//     //     x = x + K * y;
//     //     P = (I - K * H) * P;

//     //     // Update the state estimate using the pressure reading
//     //     y = pressure - H * x;
//     //     S = H * P * H.transpose() + R;
//     //     K = P * H.transpose() * S.inverse();
//     //     x = x + K * y;
//     //     P = (I - K * H) * P;

// //         // Get the current true altitude
// //         true_altitude = x(0);

// //         // Update the previous true altitudes
// //         prev_true_altitudes[0] = prev_true_altitudes[1];
// //         prev_true_altitudes[1] = prev_true_altitudes[2];
// //         prev_true_altitudes[2] = true_altitude;
// //     }

// //     // Check if the system is at apogee
// //     bool is_at_apogee() {
// //         // Check if the last 3 true altitude values are the same
// //         return prev_true_altitudes[0] == prev_true_altitudes[1] && prev_true_altitudes[1] == prev_true_altitudes[2];
// //     }

// // private:
// //     // The true altitude of the system
// //     double true_altitude;
// //     // The previous 3 true altitude values
// //     std::vector<double> prev_true_altitudes;

// //     // Matrices and vectors used by the kalman filter
// //     Eigen::Matrix2d A;  // state transition matrix
// //     Eigen::Matrix1d H;  // measurement matrix
// //     Eigen::Matrix2d Q;  // process noise covariance matrix
// //     Eigen::Matrix1d R;  // measurement noise covariance matrix
// //     Eigen::Vector2d x;
// //     Eigen::Matrix2d P;
// //     Eigen::Vector1d y;
// //     Eigen::Matrix1d S;
// //     Eigen::Matrix2d K;
// //     Eigen::Matrix2d I;
// // };
// // A class for displaying information about the system's altitude

// // int main() {
// //     // Create an altimeter and a barometer
// //     Altimeter altimeter;
// //     Barometer barometer;

// //     // Create a Kalman filter
// //     KalmanFilter filter;

// //     // Set the initial altitude and pressure readings
// //     altimeter.set_altitude(100);
// //     barometer.set_pressure(1000);

// //     // Read values from a file and store them in an array
// //     altimeter.read_from_file("altitude_values.txt");


// //     // Read values from a file and store them in an array
// //     barometer.read_from_file("pressure_values.txt");


// //     // Get the next pressure value from the array
// //     double pressure = barometer.get_pressure();

// //     // Get the next pressure value from the array
// //     double next_pressure = barometer.get_pressure();

// //     // Get the next altitude value from the array
// //     double altitude = altimeter.get_altitude();

// //     // Get the next altitude value from the array
// //     double next_altitude = altimeter.get_altitude();

// //     // Update the filter with the initial readings
// //     filter.update(altimeter.get_altitude(), barometer.get_pressure());

// //     //Read the values from the file to update the filter
// //     filter.read_and_update("values.txt");

// //     // Check if the sensor is at apogee
// //     if (filter.is_apogee()) {
// //         // The sensor is at apogee
// //         std::cout << "The sensor is at apogee" << std::endl;
// //     }
// //     else {
// //         // The sensor is not at apogee
// //         std::cout << "The sensor is not at apogee" << std::endl;
// //     }
// // }

