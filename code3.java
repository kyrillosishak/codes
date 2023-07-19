import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

public class URLExtractor {
    private static final String[] BASE_URLS = {"https://www.curlie.org/", "https://www.wikipedia.org/"};
    private static final Set<String> visitedUrls = new HashSet<>();
    private static final int MAX_THREADS = 10; // Maximum number of threads

    public static void main(String[] args) {
        for (String baseUrl : BASE_URLS) {
            crawl(baseUrl);
        }
    }

    private static void crawl(String url) {
        if (!visitedUrls.contains(url)) {
            visitedUrls.add(url);
            Thread thread = new Thread(() -> {
                try {
                    System.out.println("Visiting URL: " + url);
                    Document doc = Jsoup.connect(url).get();

                    // Extract and print the URLs on the page
                    Elements links = doc.select("a[href]");
                    for (Element link : links) {
                        String linkUrl = link.absUrl("href");
                        System.out.println("Found URL: " + linkUrl);
                        crawl(linkUrl); // Recursively crawl sub-pages
                    }
                } catch (IOException e) {
                    System.out.println("Error visiting URL: " + url);
                    e.printStackTrace();
                }
            });

            if (Thread.activeCount() < MAX_THREADS) {
                thread.start();
            } else {
                try {
                    thread.join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
