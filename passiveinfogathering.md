Passive information gathering
Type : Path + Challenge
Duration : 2 day
Deadline : 1/09/2023( start 1/09-for me)


# Pentesting steps
Pre-engagement : This is surely the phase that many novices will neglect/forget, wrongly, because it is during this phase that we will define the scope of the test and the methods that will be used for it.

Reconnaissance : Collecting as much publically accessible information about the target as possible.

Enumeration/Scanning : Discover the applications and services running on the systems, scan the ports (it's time for nmap).

Exploitation : Exploit vulnerabilities discovered on a system or application either via public exploits or via exploitation of the application/system logic.

Privilege Escalation : Once you have successfully exploited a system or application, a foothold in the jargon, you need to extend your access to the system. We talk about horizontal and vertical escalation, horizontal escalation corresponds to a transition to another user with the same permissions, vertical escalation corresponds to access to admin permissions.

Post-exploitation : This phase is broken down into several sub-steps:

Full privilege collection : Additional information with a high-privileged user.

Pivoting : Check of other potential targets.

Clean-up : Erase the traces of your intrusion.

Reporting : Report harvesters, the flaws that have been discovered, the methods used, the paths, the tools, the commands, or any other relevant information that can be used in the last phase.

Remediation : Fixing and proposing solutions for all vulnerabilities that were identified during the reporting phase.


# Passive information gathering (reconnaissance)

So, first of all, what is the osint : Open-source intelligence (OSINT) is the collection and analysis of data gathered from open sources (overt and publicly available sources) to produce actionable intelligence. OSINT is primarily used in national security, law enforcement, and business intelligence functions and is of value to analysts who use non-sensitive intelligence in answering classified, unclassified, or proprietary intelligence requirements across the previous intelligence disciplines. #Wikipedia

In short, it corresponds to all the information that can be found on the target in a public way, that is to say, which does not require any particular technical skill, it is used in the cyber but not only, it's also used in journalism and in judicial investigations 


Google Dorking

Introducing the three stages of Google Search(Ref:<https://developers.google.com/search/docs/fundamentals/how-search-works>)
Google Search works in three stages, and not all pages make it through each stage:

Crawling: Google downloads text, images, and videos from pages it found on the internet with automated programs called crawlers.
Indexing: Google analyzes the text, images, and video files on the page, and stores the information in the Google index, which is a large database.
Serving search results: When a user searches on Google, Google returns information that's relevant to the user's query.


 ***when it comes to information research, google becomes a very interesting database to exploit ...***
 
 
#  How to use it ?
Google uses its own syntax to search its database. This is very powerful to refine our searches, and we will work on this.

First, some tips

In English : It seems obvious but you will always find more content

Make it simple : Use only keywords, no need for long sentences.

Use the operators : "", ., OR, AND, *, NOT, ~, ().

Use the prefixes (advanced search operators) : site:, filetype:, cache:, and more, there are many, some are deprecated, some are more efficient than others but some combination can be very useful for a targeted search.

Don't forget to use the image search too !


# What is dorking ?
It is precisely the set of search possibilities with Google's own syntax that allows you to make very targeted searches of websites, we talk about Google Dorking.

For example, we can find sensitive information such as emails, passwords, hidden files... Identify authentication pages. Search for hardware connected to the Internet (cameras, routers, printers, ...) Check misconfigured web servers Target web server related tools like phpmyadmin, phpinfo(), site administration... Find vulnerabilities that allow to hack the target.

You can consult the following page if you want to have an overview of the possibilities ;)


check Youtube link: <https://www.youtube.com/watch?v=hrVa_dhD-iA>

***But...Who or What Regulates these "Crawlers"?***

***Aside from the search engines who provide these "Crawlers", website/web-server owners themselves ultimately stipulate what content "Crawlers" can scrape. Search engines will want to retrieve everything from a website - but there are a few cases where we wouldn't want all of the contents of our website to be indexed! Can you think of any...? How about a secret administrator login page? We don't want everyone to be able to find that directory - especially through a google search.***

Introducing Robots.txt... 

<https://pagespeed.web.dev/>-site for checking analysis of any site..its performance -SEO rating



# tryhackme/<https://tryhackme.com/room/googledorking>-task 2


Answer the questions below
Where would "robots.txt" be located on the domain "ablog.com"

ablog.com/robots.txt
If a website was to have a sitemap, where would that be located?

/sitemap.xml
How would we only allow "Bingbot" to index the website?
User-Agent: Bingbot
How would we prevent a "Crawler" from indexing the directory "/dont-index-me/"?

Disallow: /dont-index-me/
What is the extension of a Unix/Linux system configuration file that we might want to hide from "Crawlers"?

.conf


task 3

***The easier a website is to "Crawl", the more optimised it is for the "Search Engine"***

Answer the questions below
What is the typical file structure of a "Sitemap"?

xml
What real life example can "Sitemaps" be compared to?

map
Name the keyword for the path taken for content on a website

route



# Task 6  What is Google Dorking?

# SHODAN

Unlike a classic search engine, Shodan does not give the content, but just the information that the devices disclose, such as their names, locations, ip, port used and more... 


Devices run services and those services are what Shodan collects information about. For example, websites are hosted on devices that run a web service and Shodan would gather information by speaking with that web service. The information for each service is stored in an object called the banner. It is the fundamental unit of data that Shodan gathers and what you'll be searching for. 


For query search: <https://help.shodan.io/the-basics/search-query-fundamentals>


1. - Register on shodan
 username:mitushah
 pwd..google manager
 
 2. - Installation
Just copy the following command line :
pip3 install -U --user shodan

3. - add it to path: 'C:\Users\nimes\AppData\Local\Packages\PythonSoftwareFoundation.Python.3.10_qbz5n2kfra8p0\LocalCache\local-packages\Python310\Scripts'
4. I skipped 2 nad 3 point..instead i opened wsl env and installed shodan:
- wsl
- sudo apt install python3-shodan
5. Initialize it with oyur api key:
- shodan init your_api_key


# Maltego

<https://tryhackme.com/room/redteamrecon#>

# tryhackme- Red Team Recon

Command: - whois/nslookup(unix)

- dig, short for Domain Information Groper (dig)
- host
- tracert or traceroute
- whois to query the WHOIS database
nslookup, dig, or host to query DNS servers
WHOIS databases and DNS servers hold publicly available information, and querying either does not generate any suspicious traffic.

Moreover, we can rely on Traceroute (traceroute on Linux and macOS systems and tracert on MS Windows systems) to discover the hops between our system and the target host.





