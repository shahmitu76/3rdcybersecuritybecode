# ElasticSearch

Follow this:


<https://www.elastic.co/guide/en/starting-with-the-elasticsearch-platform-and-its-solutions/8.10/getting-started-observability.html>

I installed Elasticsearch on Kali.

# Installing Suricata on Ubuntu server

I have already installed Ubuntu server on my virtual machine.
So, I will use it.

- Checking the version of Ubuntu server:
lsb_release -a
![clipboard](https://i.imgur.com/9269tDp.png)

- Version of Ubuntu -22.04
- Added one more adapter- host only

## Requirements:

- Ubuntu Server 20.04 was used when putting this together. 
- Your server must have 2 ethernet adapters. Since I am using a virtual machine I set my second interface to use a host-only network.
- Whether built on a virtual machine(like mine) or on a physical box you will require 4GB of Ram and at least 60GB of hard drive .
- Please be sure to run an apt update and apt upgrade before starting so that your server is up to date. Always the best practice if you already don’t do so.

## Configuring the Sniffing Interface:

An IDS always has at least 2 interfaces. The first one is called the management interface. The second interface is commonly known as the sniffing interface. Its job is to receive all packets sent across the network. To accomplish this the interface must be put in what is called Promiscuous mode. Usually, an interface will only receive packets that are addressed to it, but when configured in promiscuous mode the interface will receive all packets.

Ubuntu by default uses a network management system called Netplan. To my best knowledge, Netplan does not support the configuring of Promiscuous mode. To work around this we will install the older network management tools and remove NetPlan.

-check the interface:
![clipboard](https://i.imgur.com/CtqVXIr.png)
two interfaces: enp0s3, enp0s8


# digital ocean 

<https://www.digitalocean.com/community/tutorials/how-to-install-suricata-on-ubuntu-20-04>

### - Setting up a basic firewall
  - Command: sudo ufw app list
  - ![clipboard](https://i.imgur.com/QsREvS2.png)
  - sudo ufw allow OpenSSh
  - Check the status of firewall: sudo ufw status
  - ![clipboard](https://i.imgur.com/ch9JARa.png)
  
### - Installing Suricata


An Intrusion Detection System (IDS) requires two primary interfaces for its operation:

Management Interface: This interface is responsible for managing the IDS system itself. It's used for accessing the IDS through a user interface, command line, or other management tools. The management interface is utilized for configuration, updating rules, system administration, and monitoring the overall health and performance of the IDS. This interface isn't involved in packet sniffing or analysis of network traffic.

Sniffing Interface (or Network Monitoring Interface): This interface is dedicated to the inspection and analysis of network traffic. It's set up to "sniff" or capture packets traversing the network. To capture packets effectively, this interface needs to be in "Promiscuous Mode."

Promiscuous Mode: By default, network interfaces only capture and process the packets that are specifically addressed to them (based on their MAC address). However, in promiscuous mode, the network interface is configured to capture all packets that it sees on the network, regardless of whether the packets are addressed to that specific interface or not.

When in promiscuous mode, the interface can receive and inspect all the packets it encounters, even if the packets are not intended for the system with that particular interface. This mode is crucial for an IDS because it allows the system to monitor all network traffic, making it possible to inspect, analyze, and detect any suspicious or potentially malicious activities traversing the network.

The capability of the sniffing interface to operate in promiscuous mode is vital for the IDS to effectively inspect all network packets, enabling it to analyze the traffic for threats, vulnerabilities, anomalies, or any irregular network behavior that might indicate a security issue.






#### Medium

# Installing a new Ubuntu server :
Name of machine: Ubuntumitunew

Followed: <https://medium.com/@fildzaanf/how-to-install-ubuntu-22-04-1-server-on-virtualbox-fe9ab1e0e8>


Now: Installing suricata again:
following this:

<https://ipninichuck.medium.com/set-up-an-ids-with-filebeat-log-shipping-11a8d2956c31>

Ok, I changed my first adapter to bridge adapter
second is still host-only

Enter the Following Commands:

sudo apt install software-properties-common

sudo add-apt-repository ppa:oisf/suricata-stable

sudo apt update

sudo apt install -y suricata

sudo suricata-update


# again following digital ocean now

<https://www.digitalocean.com/community/tutorials/how-to-install-suricata-on-ubuntu-20-04>

![clipboard](https://i.imgur.com/Ujs3ZPX.png)


After installation, in order to test suricata the following command can be used:
#sudo suricata –c /etc/suricata/suricata.yaml –i eth0 -l /var/log/suricata

source:<https://rezanourmand.wordpress.com/2015/02/01/installing-suricata-nids-on-ubuntu-virtual-machine/>

till now..followed this



<https://www.youtube.com/watch?v=UXKbh0jPPpg>


<https://www.youtube.com/watch?v=xXte5RplzBc>



Following medium from start


Replace Netplan Instructions:

Enter the following Commands:

ip addr (Note: write down the interface names, my VM used enp0s17 and enp0s8)

sudo apt install -y ifupdown

Create the Following File:

sudo nano /etc/network/interfaces

File text( replace interface names with the ones you wrote down earlier if needed):

#loopback

auto lo

iface lo inet loopback

#management interface

allow-hotplug enp0s8

iface enp0s8 inet dhcp

#sniffing interface

allow-hotplug enp0s3

iface enp0s3 inet manual

up ifconfig enp0s3 promisc up

down ifconfig enp0s3 promisc down

Shut Down Network Services, remove netplan and reboot with the Following Commands:

sudo service systemd-networkd stop

sudo apt remove -y netplan

sudo apt install net-tools -y

sudo reboot now (Note: You could just restart the Interfaces, but I prefer to restart the whole thing.)

Confirm that your interfaces Look like the image below with the following command:

ip addr

![clipboard](https://i.imgur.com/ZWW9hAb.png)


add any ip ranges to the home-net variable list that are not already covered
In the section on logging outputs be sure that eve-log has a yes value for enabled
Use the key combination ‘ctl \’ to bring up the find and replace option. Replace eth0 with the name of your sniffing interface( in my case I had enp0s8)
Scroll down to checksum-validation under the Flow section and set the value to no- haven't done yet



# The components that you will use to build your own SIEM are:

Elasticsearch to store, index, correlate, and search the security events that come from your Suricata server.
Kibana to display and navigate around the security event logs that are stored in Elasticsearch.
Filebeat to parse Suricata’s eve.json log file and send each event to Elasticsearch for processing.
Suricata to scan your network traffic for suspicious events, and either log or drop invalid packets.

medium:

add any ip ranges to the home-net variable list that are not already covered- added both subnets
In the section on logging outputs be sure that eve-log has a yes value for enabled
Use the key combination ‘ctl \’ to bring up the find and replace option. Replace eth0 with the name of your sniffing interface( in my case I had enp0s3)
Scroll down to checksum-validation under the Flow section and set the value to no- i did in stream section


Starting again
1. Installing new ubuntu server
2. Installing Suricata: <https://www.youtube.com/watch?v=xXte5RplzBc&t=0s>
3. 



