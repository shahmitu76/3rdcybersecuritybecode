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

