## Basic Web Crawler
Runs on single machine with a single thread

1. Start with a URL pool that contains all the websites that we want to crawl
2. For each URL, issue a HTTP GET request to fetch the page content
3. Parse each content and extract potential URL's that we want to crawl
4. Add new URL's to the pool and keep crawling

## Distributed Web Crawler Challenges

### Crawling Frequency

* This is usecase specific. Different crawl frequency for different websites.
* Ex - If we want to get the latest news from last hour, our crwaler needs to keep crawling the news website every hour.
* For small websites, we can use their robots.txt to naviagate their pages.

### Dedup URL's

In a single machine, you can keep the URL's in memory and remove duplicate entries. What about distributed systems?
Using Bloom filter, we can tell if a url is definitely not in the pool or probably in the pool.

### Miscellaneous
1. Handle encode/decode issue when HTML contains non unicode characters
2. Webpages contain image, videos and pdfs which might be a problem
3. If the URL is a downloadable link, we need to skip that url. Add timeouts. 
4. When the system gets scaled to certain level, DNS lookup can be a bottleneck and we may build our own DNS server.









