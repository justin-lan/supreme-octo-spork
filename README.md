# Assessment 2 
## _Justin Horan - z5329473_
## 1. Introduction 
This application and exploit was produced for ZEIT8042’s Exploit Development course, assessment 2. 
The application is a 32bit application built on a Kali Linux 2021.2. It is designed to take the input of a file via command line, create a buffer in memory, write the file to memory then write the contents to the screen. The security controls used in this application are ASLR and NX bit. 

The program will be exploited via a “return to lib c” style buffer overflow that will bypass the ASLR and NX bit security control. The exploit will take the form of a brute force attack, where the program will be launched from a python file that will run until a shell is produced. 

A summary of the structure of this project is below: 
| Directory | Contents |
| ------ | ------ |
| /app | Source code for vulnerable application.|
| /exploit | Python exploit script |

## 2. Application 
### 2.0 Build Environment: 
See below for information on the build environment. 
```
$ uname -a
Linux kali 5.9.0-kali1-amd64 #1 SMP Debian 5.9.1-1kali2 (2020-10-29) x86_64 GNU/Linux
$ cat /etc/os-release
PRETTY_NAME="Kali GNU/Linux Rolling"
NAME="Kali GNU/Linux"
ID=kali
VERSION="2020.4"
VERSION_ID="2020.4"
VERSION_CODENAME="kali-rolling"
ID_LIKE=debian
...
```
### 2.1 Dependencies
 This project requires the following software to compile the program and execute the software. 
 - GCC -GNU Code Compiler (pre-installed) with multilib 
```
sudo apt-get install gcc-multilib -y
```
 - GDB - GNU Debugger 
```
sudo apt-get install gdb
```
 - PEDA - Python Exploit Development Assistance for GDB
```sh
git clone https://github.com/longld/peda.git ~/peda
echo "source ~/peda/peda.py" >> ~/.gdbinit
```
 - ASLR will be turned on
```
echo 2 | sudo tee /proc/sys/kernel/randomize_va_space
```
### 2.2 Compiling 
Compiling the application is quite simple. Run the make file below. 
```
cd ~/Desktop/8042-a2-tmpl/app
make -f makefile
```
### 2.3 Execution 
The program requires input from the command line, you need to specify the file in which you are giving it. 
I have provided a sample of a non-malicious file (good.txt) which will demonstrate the program working correctly. 
The program will successfully complete when it returns; 'Program Successful, exiting'.
```sh
./VulnApp good.txt
```
## 3. Exploit 
The exploit will be run from a python file in /exploit. The program will attempt to run the application with defined stack addressses untill it finds lands on the correct address and provides a shell. It will continue to run untill it gets the shell.  
```sh
cd ~/Desktop/8042-a2-tmpl/exploit
python ./exploit.py
```
## 4. Inspiration: 
Some sources that really helped for this project are listed below:
<https://www.youtube.com/watch?v=NCLUm8geskU&t=66s> 
<https://seedsecuritylabs.org/Labs_16.04/Software/Return_to_Libc/> 
<https://www.youtube.com/watch?v=DLmWb-yeFTY> 

