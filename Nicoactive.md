ffuf -w subdomains.txt -u http://website.com/ -H “Host: FUZZ.website.com
De smet tristan1:36 PM
nmap --script dns-brute <domain>
Thomas Depas1:37 PM
you have an other oldschool version called dirbuster with a gui
De smet tristan1:39 PM
if you need wordlist there's this github repo 
 with a lot of them here 
 : https://github.com/danielmiessler/SecLists
De smet tristan1:44 PM
on the top of your nikto respons you had the answer too

# bc_active_info_gathering

BeCode Module - Active Information Gathering

Ip : 10.12.1.36

## DNS Enumeration

1. What is the ip address of adlp-corp.com ?
    ```bash
    dig adlp-corp.com +short
    ```
    > 52.51.133.160
3. What is the TXT record of adlp-corp.com? 
    ```bash
    dig adlp-corp.com +short -t txt
    ```
    > "BC{DESCRIPTIVE-DOMAIN-TXT}"
4. What are the MX records of becode.org ?
    ```bash
    dig becode.org -t mx +short
    ```
    > 1 aspmx.l.google.com.
    > 10 alt3.aspmx.l.google.com.
    > 10 alt4.aspmx.l.google.com.
    > 5 alt1.aspmx.l.google.com.
    > 5 alt2.aspmx.l.google.com.

5. What are the MX records of adlp-corp.com ?
    ```bash
    dig adlp-corp.com -t mx +short
    ```
    > 1 aspmx.l.google.com.
    > 10 alt3.aspmx.l.google.com.
    > 10 alt4.aspmx.l.google.com.
    > 5 alt1.aspmx.l.google.com.
    > 5 alt2.aspmx.l.google.com.

6. What is the first NS name server of adlp-corp.com?
    ```bash
    dig adlp-corp.com -t ns +short
    ```
    > ns-1185.awsdns-20.org.

7. Uses a brute force tool to find subdomains of adlp-corp.com. How many did you find?
    ```bash
    ffuf -w /usr/share/wordlists/subdomain.txt -u https://FUZZ.adlp-corp.com
    ```
    > 7

8. Use theHarvester tool at becode.org. How many Linkedin Users? 
    ```bash
    theHarvester -d becode.org -b all  
    ```
    > 0

9.  Use theHarvester tool at becode.org. How many ip addresses did you find? 
    ```bash                                                         
    theHarvester -d becode.org -b all
    ```
    > [*] IPs found: 32 

10. Write a small script to attempt a zone transfer from adlp-corp.com using a higher-level
scripting language such as Python, Perl, or Ruby.
    > see scripts/dns_transfer.py

1. Write a small script to attempt a brute force search for subdomains using a higher level scripting language such as Python, Perl or Ruby.
    > see scripts/subdomain_bruteforce.py



## Port Scanning

1. How many tcp ports are open on the box? What command did you use?
    ```
    nmap -p- -sT 10.12.1.36
    ```
    > 31
    
2. How many udp ports are open on the box? What command did you use?
    ```
    nmap -p- -sU 10.12.1.36
    ```

3. What is the version of ftp?
    > 21/tcp   open  ftp         vsftpd 2.3.4

4. What is the version of ssh?
    > 22/tcp   open  ssh         OpenSSH 4.7p1 Debian 8ubuntu1 (protocol 2.0)

5. What is the version of Apache?
    > 80/tcp   open  http        Apache httpd 2.2.8 ((Ubuntu) DAV/2)

6. Is anonymous ftp access allowed on the box? What command did you use? (Use only nmap)
    ```
    nmap -sT -sV -sC 10.12.1.36
    ```
    > |_ftp-anon: Anonymous FTP login allowed (FTP code 230)

7. Do a SYN scan. Which command did you use?
    ```
    sudo nmap -sS 10.12.1.36
    ```

8. Do a scan that bypasses a firewall. What command did you use?
    ```
    sudo nmap -sF -T4 10.12.1.36
    ```

9.  Run a scan with the default NSE scripts. Which flag do you use?
    ```
    nmap --script default 10.12.1.36
    ```

10. What service occupies port 8180?
    > Apache Tomcat/5.5

11. What is the salt of the mysql service?
    > Ne1_o/9oDH{Ri<+c1jBL

12. What is the domain name ?
    > localdomain

13. What is the FQDN of the box ? 
    > metasploitable.localdomain

14. What is the os version ? 
    > Unix (Samba 3.0.20-Debian)

15. What is the version of Samba ?
    > Samba 3.0.20-Debian

16. Wat is the name of the box ?
    > metasploitable

17. Do a scan on the subnet 10.xx.1.0/24. How many IP addresses respond?  What command did you use?

   Charleroi : 10.11.0.1/24

   Bruxelles : 10.12.0.1/24

   Ghent : 10.13.0.1/24

    ```
    nmap -sL -n 10.12.0.1/24
    ```
    > Charleroi: Nmap done: 256 IP addresses (1 host up) scanned in 7.56 seconds
    > Bruxelles: Nmap done: 256 IP addresses (1 host up) scanned in 7.69 seconds
    > Ghent: Nmap done: 256 IP addresses (1 host up) scanned in 26.05 seconds

18. Do the same thing but with the top port option at 10. What command did you use?
    ```
    nmap --top-ports 10 10.12.0.1/24
    ```

## Vulnerability Scanning

1. Do a vulnerability scan with nmap. 
    ```
    nmap -sV -p- --script vulners 10.12.1.36
    ```
    - How many vulnerable services are there?
        > 7
    - How many vulnerabilities did nmap find & what are those services?
        ```
            22/tcp      -   11
            53/tcp      -   54
            80/tcp      -   109
            2121/tcp    -   40
            3306/tcp    -   48
            5432/tcp    -   83
            8180/tcp    -   2
        
            TOTAL       -   ~347
        ```

    > see docs/nmap_vulnerabilities.txt 

3. Do a vulnerability scan with Nessus. -> nah
- How many vulnerabilities did nessus find ?
- What are these services?

## Samba - [Not Setup Properly]

- Do the following exercises without authentication.
- There are many tools to get the same answers. It doesn't matter which tool, the important thing is the answer.

COMMAND:
```bash
nmap -sV -sC -T4 10.12.1.36
```

1. What is the OS ?
    > Unix
2. What is the version of samba on the box? 
    > Samba 3.0.20-Debian 
3. How many group names are there? (use nbtstat)
    > Your response 
4. What is the FQDN ?
    > metasploitable.localdomain
5. What is the Netbios computer name.
    > METASPLOITABLE
6. How many disks are shared?
    > 5
7. Which one is available for reading and writing? 
    > tmp
8. What flag did you find when you logged in?
    > UNAVAILABLE
9. What is the path that begins with ``c:\`` in this file?
    > UNAVAILABLE
10. How many users can you find ?
    > UNAVAILABLE

## SMTP

1. How many commands are allowed on port 25?
    > [14 commands](https://www.geeksforgeeks.org/smtp-commands/)
2. How many users can you enumerate via port 25?
    > 28 
3. Send a mail with the email admin@local to root@local by connecting to the smtp server.

    > used [this tutorial](https://www.baeldung.com/linux/check-smtp-via-terminal)

    ```
    telnet 10.12.1.36 25
    Trying 10.12.1.36...
    Connected to 10.12.1.36.
    Escape character is '^]'.
    220 metasploitable.localdomain ESMTP Postfix (Ubuntu)
    helo metasploitable.localdomain
    250 metasploitable.localdomain
    mail from:admin@metasploitable.localdomain
    250 2.1.0 Ok
    rcpt to:root@metasploitable.localdomain
    250 2.1.5 Ok
    data
    354 End data with <CR><LF>.<CR><LF>
    from: admin@metasploitable.localdomain
    Subject: This is a test
    Hi there :)
    How are you doing?
    .
    250 2.0.0 Ok: queued as 495B5CC46
    ```
4. Connect to ssh with msfadmin:msfadmin creds and check if you have sent the mail
    > msfadmin@metasploitable:/var/spool/mail$ sudo cat root


## HTTP

### FIRST RUN GOBUSTER & NIKTO

1. How many files could you find on port 80?
    > 6 folders - hundreds of files according to feroxbuster

    COMMANDS:
    
    METASPLOIT:
    ```bash
        msfconsole
        msf6 > use auxiliary/scanner/http/dir_scanner
        msf6 auxiliary(scanner/http/dir_scanner) > show options
        msf6 auxiliary(scanner/http/dir_scanner) > set RHOSTS 10.12.1.36
        msf6 auxiliary(scanner/http/dir_scanner) > run
    ```

    [GOBUSTER](https://github.com/OJ/gobuster):
    ```bash
    gobuster dir -u http://10.12.1.36 -w /usr/share/wordlists/dirb/common.txt
    ```
    > see docs/gobuster_big.txt

    [FEROXBUSTER](https://github.com/epi052/feroxbuster):
    ```bash
    feroxbuster -u http://10.12.1.36 -w /usr/share/wordlists/dirb/common.txt --silent
    ```
    > see docs/ferox_common.txt

    [FFUF](https://github.com/ffuf/ffuf):
    ```bash
    ffuf -c -w /usr/share/wordlists/dirb/common.txt -u https://adlp-corp.com/FUZZ
    ```

2. What is the version of apache?
    ```
    nmap -sV 10.12.1.36 -p 80
    ```
    > Apache httpd 2.2.8
3. What is the version of php ?
    > PHP/5.2.4-2ubuntu5.10 according to curl scan
4. What server extension is installed?
    > mod_dav according to Wappalyzer
6. What is the name of the file in testoutput?
    > ESAPI_logging_file_test - found by accessing http://10.12.1.36/test/testoutput
7. Do a scan with Nikto on port 80.
    ```bash
    nikto -h 10.12.1.36 -p 80
    ```
    > see docs/http_nikto.txt
8. An informative file in php seems to be available, what is its name?
    > phpinfo.php according to Nikto
9. What application has a name that starts with T and ends with Y?
    > ---
10. What curl command can you use to see the server version?
    ```
    curl -I -L 10.12.1.36
    ```
11. What tool for enumerating files does it do recursively? (By default)
    > dirbuster
12. What other administration application is currently also on port 80?
    > phpMyAdmin 


## Other

*With rpc protocol*

1. Connect to RPC Client
    ```
    rpcclient -U "" -N 10.12.1.36
    ```

2. With the rpc protocol, how many users can you find ?
    ```
    user:[games] rid:[0x3f2]
    user:[nobody] rid:[0x1f5]
    user:[bind] rid:[0x4ba]
    user:[proxy] rid:[0x402]
    user:[syslog] rid:[0x4b4]
    user:[user] rid:[0xbba]
    user:[www-data] rid:[0x42a]
    user:[root] rid:[0x3e8]
    user:[news] rid:[0x3fa]
    user:[postgres] rid:[0x4c0]
    user:[bin] rid:[0x3ec]
    user:[mail] rid:[0x3f8]
    user:[distccd] rid:[0x4c6]
    user:[proftpd] rid:[0x4ca]
    user:[dhcp] rid:[0x4b2]
    user:[daemon] rid:[0x3ea]
    user:[sshd] rid:[0x4b8]
    user:[man] rid:[0x3f4]
    user:[lp] rid:[0x3f6]
    user:[mysql] rid:[0x4c2]
    user:[gnats] rid:[0x43a]
    user:[libuuid] rid:[0x4b0]
    user:[backup] rid:[0x42c]
    user:[msfadmin] rid:[0xbb8]
    user:[telnetd] rid:[0x4c8]
    user:[sys] rid:[0x3ee]
    user:[klog] rid:[0x4b6]
    user:[postfix] rid:[0x4bc]
    user:[service] rid:[0xbbc]
    user:[list] rid:[0x434]
    user:[irc] rid:[0x436]
    user:[ftp] rid:[0x4be]
    user:[tomcat55] rid:[0x4c4]
    user:[sync] rid:[0x3f0]
    user:[uucp] rid:[0x3fc]
    ```
    > rpcclient $> enumdomusers
    > 34 users

3. What is the rid of msfadmin?
    > user:[msfadmin] rid:[0xbb8]
    > rpcclient $> enumdomusers

4. What is the path of msfadmin's profile?
    > Profile Path:   \\metasploitable\msfadmin\profile
    > rpcclient $> queryuser 0xbb8

5. When did msadmin last change password?
    > Password last set Time   :      Wed, 28 Apr 2010 08:56:18 CEST

6. When should msfadmin change its password?
    > Password can change Time :      Wed, 28 Apr 2010 08:56:18 CEST
    > Password must change Time:      Thu, 14 Sep 30828 04:48:05 CEST

TO EXPLOIT & GAIN ACCESS, FOLLOW [THIS TUTORIAL](https://www.computersecuritystudent.com/SECURITY_TOOLS/METASPLOITABLE/EXPLOIT/lesson4/index.html)

## SNMP 
SNMP stands for Simple Network Management Protocol which is used to exchange management information between network devices. SNMP allows an administrator to gather information about the host on which SNMP is running. It is also possible to modify this information.

Managed devices such as routers, hubs, switches, servers and desktops are typically configured with SNMP. An SNMP-configured device often includes an agent, which performs functions such as collecting information about the environment that can be used later by other utilities.

read this documentation :  https://www.pentestpartners.com/security-blog/snmp-simply-not-my-problem-or-is-it/


**Tools :**
- snmpwalk: snmpwalk -v 1 -c public 192.168.99.144
- snmpcheck: snmpcheck -t 192.168.99.144