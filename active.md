# DNS enumeration
DNS enumeration is the process of locating all the DNS servers and their corresponding records for an organization. 

- The examples of tool that can be used for DNS enumeration are NSlookup, DNSstuff, American Registry for Internet Numbers (ARIN), and Whois. To enumerate DNS, you must have understanding about DNS and how it works.
- Commands:

- nslookup --type=A website.thm
- nslookup --type=CNAME website.thm
- nslookup --type=MX website.thm
- nslookup --type=TXT website.thm


- We all know that DNS servers are basically computers connected to the Internet, and that helps us to resolve hostnames into IP addresses. They're in charge of managing and processing DNS requests from clients that need to fetch fresh domain name information, along with DNS records.

That's where the weak link shows up, thanks to the way the DNS was built. It's a bit vulnerable, which allows us to perform DNS enumeration (also known as DNS recon) easily.


# Query engines(<https://securitytrails.com/blog/subdomain-scanner-find-subdomains>)-read

-site:cloudflare.com -www
to search for pages and content specifically on the "cloudflare.com" domain but excluding any pages with URLs that start with "www."

Subdomain tools:
<https://securitytrails.com/blog/subdomain-scanner-find-subdomains>

# Top 7 DNS enumeration tools

lost lot of info

# nmap
<https://tryhackme.com/room/furthernmap>(Read it)

Every computer has a total of 65535 available ports; however, many of these are registered as standard ports. For example, a HTTP Webservice can nearly always be found on port 80 of the server. A HTTPS Webservice can be found on port 443. Windows NETBIOS can be found on port 139 and SMB can be found on port 445. It is important to note; however, that especially in a CTF setting, it is not unheard of for even these standard ports to be altered, making it even more imperative that we perform appropriate enumeration on the target.

So, why nmap? The short answer is that it's currently the industry standard for a reason: no other port scanning tool comes close to matching its functionality (although some newcomers are now matching it for speed). It is an extremely powerful tool – made even more powerful by its scripting engine which can be used to scan for vulnerabilities, and in some cases even perform the exploit directly! Once again, this will be covered more in upcoming tasks.

 Nmap is installed by default in both Kali Linux and the TryHackMe Attack Box.
 
 Tryhackme:
 task3: Answers:
 Answer the questions below
What is the first switch listed in the help menu for a 'Syn Scan' (more on this later!)?

-sS
Which switch would you use for a "UDP scan"?

-sU
If you wanted to detect which operating system the target is running on, which switch would you use?

-O
Nmap provides a switch to detect the version of the services running on the target. What is this switch?

-sV
The default output provided by nmap often does not provide enough information for a pentester. How would you increase the verbosity?

-v
Verbosity level one is good, but verbosity level two is better! How would you set the verbosity level to two?
(Note: it's highly advisable to always use at least this option)

-vv
We should always save the output of our scans -- this means that we only need to run the scan once (reducing network traffic and thus chance of detection), and gives us a reference to use when writing reports for clients.

What switch would you use to save the nmap results in three major formats?

-oA
What switch would you use to save the nmap results in a "normal" format?

-oN
A very useful output format: how would you save results in a "grepable" format?

-oG
Sometimes the results we're getting just aren't enough. If we don't care about how loud we are, we can enable "aggressive" mode. This is a shorthand switch that activates service detection, operating system detection, a traceroute and common script scanning.

How would you activate this setting?

-A
Nmap offers five levels of "timing" template. These are essentially used to increase the speed your scan runs at. Be careful though: higher speeds are noisier, and can incur errors!

How would you set the timing template to level 5?

-T5
We can also choose which port(s) to scan.

How would you tell nmap to only scan port 80?

-p 80
How would you tell nmap to scan ports 1000-1500?

-p1000-1500
A very useful option that should not be ignored:

How would you tell nmap to scan all ports?

-p-
How would you activate a script from the nmap scripting library (lots more on this later!)?

--script
How would you activate all of the scripts in the "vuln" category?

--script=vuln



task4:
When port scanning with Nmap, there are three basic scan types. These are:

TCP Connect Scans (-sT)
SYN "Half-open" Scans (-sS)
UDP Scans (-sU)
Additionally there are several less common port scan types, some of which we will also cover (albeit in less detail). These are:

TCP Null Scans (-sN)
TCP FIN Scans (-sF)
TCP Xmas Scans (-sX)

task 5:

As a brief recap, the three-way handshake consists of three stages. First the connecting terminal (our attacking machine, in this instance) sends a TCP request to the target server with the SYN flag set. The server then acknowledges this packet with a TCP response containing the SYN flag, as well as the ACK flag. Finally, our terminal completes the handshake by sending a TCP request with the ACK flag set.

In other words, if Nmap sends a TCP request with the SYN flag set to a closed port, the target server will respond with a TCP packet with the RST (Reset) flag set. By this response, Nmap can establish that the port is closed.



If, however, the request is sent to an open port, the target will respond with a TCP packet with the SYN/ACK flags set. Nmap then marks this port as being open (and completes the handshake by sending back a TCP packet with ACK set).

task6; A SYN scan, also known as a "half-open" scan, is faster than a standard TCP Connect scan (also known as a "full-open" scan) because it doesn't complete the full three-way handshake for every port being scanned. Instead, it sends only the initial SYN (Synchronize) packet of the handshake and then listens for responses. 

When using a SYN scan to identify closed and filtered ports, the exact same rules as with a TCP Connect scan apply.

If a port is closed then the server responds with a RST TCP packet. If the port is filtered by a firewall then the TCP SYN packet is either dropped, or spoofed with a TCP reset.

In this regard, the two scans are identical: the big difference is in how they handle open ports.

[1] SYN scans can also be made to work by giving Nmap the CAP_NET_RAW, CAP_NET_ADMIN and CAP_NET_BIND_SERVICE capabilities; however, this may not allow many of the NSE scripts to run properly.

Task 7:

Answer the questions below
If a UDP port doesn't respond to an Nmap scan, what will it be marked as?
open|filtered
When a UDP port is closed, by convention the target should send back a "port unreachable" message. Which protocol would it use to do so?

icmp


task 9:

To perform a ping sweep, we use the -sn switch in conjunction with IP ranges which can be specified with either a hypen (-) or CIDR notation. i.e. we could scan the 192.168.0.x network using:

nmap -sn 192.168.0.1-254
or

nmap -sn 192.168.0.0/24


The -sn switch tells Nmap not to scan any ports -- forcing it to rely primarily on ICMP echo packets (or ARP requests on a local network, if run with sudo or directly as the root user) to identify targets. In addition to the ICMP echo requests, the -sn switch will also cause nmap to send a TCP SYN packet to port 443 of the target, as well as a TCP ACK (or TCP SYN if not run as root) packet to port 80 of the target.


Ttask 10;

NSEScripts:

The Nmap Scripting Engine (NSE) is an incredibly powerful addition to Nmap, extending its functionality quite considerably. NSE Scripts are written in the Lua programming language, and can be used to do a variety of things: from scanning for vulnerabilities, to automating exploits for them. The NSE is particularly useful for reconnaisance, however, it is well worth bearing in mind how extensive the script library is.

There are many categories available. Some useful categories include:

safe:- Won't affect the target
intrusive:- Not safe: likely to affect the target
vuln:- Scan for vulnerabilities
exploit:- Attempt to exploit a vulnerability
auth:- Attempt to bypass authentication for running services (e.g. Log into an FTP server anonymously)
brute:- Attempt to bruteforce credentials for running services
discovery:- Attempt to query running services for further information about the network (e.g. query an SNMP server).

task11:

To run a specific script, we would use --script=<script-name> , e.g. --script=http-fileupload-exploiter.

Multiple scripts can be run simultaneously in this fashion by separating them by a comma. For example: --script=smb-enum-users,smb-enum-shares.

Some scripts require arguments (for example, credentials, if they're exploiting an authenticated vulnerability). These can be given with the --script-args Nmap switch. An example of this would be with the http-put script (used to upload files using the PUT method). This takes two arguments: the URL to upload the file to, and the file's location on disk.  For example:

nmap -p 80 --script http-put --script-args http-put.url='/dav/shell.php',http-put.file='./shell.php'

Note that the arguments are separated by commas, and connected to the corresponding script with periods (i.e.  <script-name>.<argument>).


Nmap scripts come with built-in help menus, which can be accessed using nmap --script-help <script-name>. 

What optional argument can the ftp-anon.nse script take?

to be dealt again

task12: we should know how to use the script and where to find them:
use: Nmap scripts come with built-in help menus, which can be accessed using nmap --script-help <script-name>. 
find:  is the local storage on your attacking machine. Nmap stores its scripts on Linux at /usr/share/nmap/scripts. All of the NSE scripts are stored in this directory by default -- this is where Nmap looks for scripts when you specify them.

task11:read full

task12:

Search for "smb" scripts in the /usr/share/nmap/scripts/ directory using either of the demonstrated methods.
What is the filename of the script which determines the underlying OS of the SMB server?
command:cd /usr/share/nmap/scripts
grep "smb" script.db
answer:
smb-os-discovery.nse
Read through this script. What does it depend on?

deal later

task 13: firewall evasion

There are a variety of  switches which Nmap considers useful for firewall evasion.

The following switches are of particular note:

-Pn:=

-f:- Used to fragment the packets (i.e.  Nmap provides an option for this: -Pn, which tells Nmap to not bother pinging the host before scanning it. This means that Nmap will always treat the target host(s) as being alive, effectively bypassing the ICMP block; however, it comes at the price of potentially taking a very long time to complete the scan (if the host really is dead then Nmap will still be checking and double checking every specified port).split them into smaller pieces) making it less likely that the packets will be detected by a firewall or IDS.
An alternative to -f, but providing more control over the size of the packets: --mtu <number>, accepts a maximum transmission unit size to use for the packets sent. This must be a multiple of 8.
--scan-delay <time>ms:- used to add a delay between packets sent. This is very useful if the network is unstable, but also for evading any time-based firewall/IDS triggers which may be in place.
--badsum:- this is used to generate in invalid checksum for packets. Any real TCP/IP stack would drop this packet, however, firewalls may potentially respond automatically, without bothering to check the checksum of the packet. As such, this switch can be used to determine the presence of a firewall/IDS.

Task 14: practical-later to bve done
nmap kamkar github:

2. Connect to the vpn and use the 10.12.1.36 to answer the following questions:
⚠️⚠️⚠️ Please save your answers. Your coaches may ask you for a copy of all your answers at the end of the challenge. ⚠️⚠️⚠️


Ip : 10.12.1.36

First open VPN connection:
1. Make sure Vpn file is in shared folder /media/sf_sharedmituvpn. Otherwise share it from c:/githubciscopackettraceractivity/shared_mitu1. File name:C:\Githubciscopackettraceractivity\sharedmitu1\openvpn...
2. go to kali and give the commands:
3. cd /media/sf_sharedmitu1
4. sudo open vpn<file name>
5. it will ask you user name and pwd
6. done
To check which server is open:
1. command:nmap -sV 10.12.1.0/24
2.it shows many hosts are up- i chose 10.12.1.36

How many tcp ports are open on the box? What command did you use?

Your response-

31

How many udp ports are open on the box? What command did you use?

Your response: 0

What is the version of ftp?

Your response:vsftpd 2.3.4

What is the version of ssh?

Your response: OpenSSH 4.7p1 Debian 8ubuntu1(protocol 2.0)

What is the version of Apache?

Your response: Apace httpd 2.2.8((Ubuntu) DAV/2)

Is anonymous ftp access allowed on the box? What command did you use? (Use only nmap)
anonymous ftp access allowed on the box?

Your response: 

without nmap
:

![clipboard](https://i.imgur.com/Vs4Qn1G.png)

with nmap:

![clipboard](https://i.imgur.com/WZNzidK.png)


Do a SYN scan. Which command did you use?

![clipboard](https://i.imgur.com/Wj42WxO.png)


Your response

Do a scan that bypasses a firewall. What command did you use?

Your response:


Run a scan with the default NSE scripts. Which flag do you use?

Your response
nmap -sC -sV 10.12.1.36

What service occupies port 8180?

 Apache Tomcat/Coyote jsp engine 1.1
Your response

What is the salt of the mysql service?

Your response: Salt
:goz6:aZ,]p;u]Raq4Nk


What is the domain name ?

Your response-local domain

What is the FQDN of the box ?

Your response-metaspoilt.localdoamin

What is the os version ?

Your response: unix(Samba 3.0.20-Debian)

What is the version of Samba ?

Your response same as above

Wat is the name of the box ?

Your response-metasploitable

Do a scan on the subnet 10.xx.1.0/24. How many IP addresses respond? What command did you use? Charleroi : 10.11.0.1/24 Bruxelles : 10.12.0.1/24 Ghent : 10.13.0.1/24

Your response:
nmap -sV 10.11.0.1/24

Do the same thing but with the top port option at 10. What command did you use?

Your response

![clipboard](https://i.imgur.com/cx4uAb7.png)

# http:

Exercises
⚠️⚠️⚠️ Please save your answers. Your coaches may ask you for a copy of all your answers at the end of the challenge. ⚠️⚠️⚠️

IP : 10.12.1.4x

How many files could you find on port 80?
Your response

What is the version of apache?
Your response

What is the version of php ?
Your response

What server extension is installed?
Your response

What is the name of the file in testoutput?
Your response

Do a scan with Nikto on port 80.
Your response
An informative file in php seems to be available, what is its name?

What application has a name that starts with T and ends with Y?
Your response

What curl command can you use to see the server version?
Your response

What tool for enumerating files does it do recursively? (By default)
Your response

What other administration application is currently also on port 80?
Your response


# Samba Enumeration

Read this documentation:

https://www.hackingarticles.in/a-little-guide-to-smb-enumeration/

Exercises
⚠️⚠️⚠️ Please save your answers. Your coaches may ask you for a copy of all your answers at the end of the challenge. ⚠️⚠️⚠️

Important : Important: you must be connected to the vpn

Do the following exercises without authentication.

There are many tools to get the same answers. It doesn't matter which tool, the important thing is the answer.

IP : 10.12.1.4x
What is the OS ?
I have chosen 10.12.1.40
Your response: Linux
Command: nmap -sV 10.12.1.0/24
![clipboard](https://i.imgur.com/hu05Kpt.png)
![clipboard](https://i.imgur.com/Woo5Z6S.png)


What is the version of samba on the box?
Your response-
Samba 3.0.20-Debian
Command- smbclient -L //10.12.1.40
![clipboard](https://i.imgur.com/3vR94KU.png)

How many group names are there? (use nbtstat)
Your response- nbtstat not working
use same command: Command- smbclient -L //10.12.1.40

ans: metaspoilt

What is the FQDN ?
Your response

What is the Netbios computer name.
Your response-METASPOILtable
command-nbtscan 10.12.1.40
ref:<https://www.baeldung.com/linux/hostname-from-ip-address#:~:text=3.1.-,Using%20the%20Command%20nmblookup,IP%20addresses%20in%20a%20network.&text=As%20you%20can%20see%20in,of%20the%20given%20IP%20address.>

nmap --script smb-os-discovery 10.12.1.40

![clipboard](https://i.imgur.com/vHEVmpQ.png)
![clipboard](https://i.imgur.com/ZEHIs8l.png)


How many disks are shared?
Your response

Which one is available for reading and writing?
Your response

What flag did you find when you logged in?
Your response

What is the path that begins with c:\ in this file?
Your response

How many users can you find ?
Your response

IP : 10.12.1.36
What is the OS version?
Your response

What is the version of samba on the box?
Your response

How many group names are there? (use nbtstat)
Your response

What is the FQDN ?
Your response

What is the Netbios computer name.
Your response

How many disks are shared?
Your response

Which one is available for reading and writing?
Your response

What flag did you find when you logged in?
Your response

What is the path that begins with c:\ in this file?
Your response

How many users can you find ?
Your response