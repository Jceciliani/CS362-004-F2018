import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   //String [] mySchemes = {"http"};
   //UrlValidator val = new UrlValidator(mySchemes);
   //UrlValidator val = new UrlValidator(mySchemes, null, UrlValidator.ALLOW_2_SLASHES);
 
   //UrlValidator val = new UrlValidator(UrlValidator.ALLOW_2_SLASHES + UrlValidator.NO_FRAGMENTS);
   
   public void testManualTest()
   {	
	   //You can use this function to implement your manual testing
	   System.out.println("----- Starting Unit Tests -----");
	   UrlValidator val = new UrlValidator();
	   
	   //Should be valid
	   String url = "http://google.com";
       if (val.isValid(url)) {
           System.out.println("1. success: url is valid - " + url);
       } else {
           System.out.println("1. failure: url is invalid - " + url);
       }
       //Should be invalid
       url = "hxxp://google.com";
       if (val.isValid(url)) {
           System.out.println("2. failure: url is valid - " + url);
       } else {
           System.out.println("2. success: url is invalid - " + url);
       }
       //Should be valid
       url = "https://www.google.com";
       if (val.isValid(url)) {
           System.out.println("3. success: url is valid - " + url);
       } else {
           System.out.println("3. failure: url is invalid - " + url);
       }
       //Should be valid
       url = "ftp://google.com";
       if (val.isValid(url)) {
           System.out.println("4. success: url is valid - " + url);
       } else {
           System.out.println("4. failure: url is invalid - " + url);
       }
   }
   
   
   public void testYourFirstPartition()
   {
	   //You can use this function to implement your First Partition testing	  
	   //Expected 'valid' tests
	   System.out.println("\n----- Starting Partition 1 Tests -----");
	   String url;
	   String schemes[] = {"http://", "https://", "ftp://"};
	   String authorities[] = {"www.google.com", "www.amazon.com", "oregonstate.edu"};
	   
	   UrlValidator val = new UrlValidator();
	   
	   for (int i = 0; i < 3; i++){
		   for (int j = 0; j < 3; j++){
			   url = schemes[i] + authorities[j];
			   if (val.isValid(url)){
				   System.out.println("success: url is valid - " + url);
		       } else {
		           System.out.println("failure: url is invalid - " + url);
			   }
		   }
	   }
   }
   
   public void testYourSecondPartition()
   {
	   //You can use this function to implement your Second Partition testing	   
	   //Expected 'invalid' tests
	   System.out.println("\n----- Starting Partition 2 Tests -----");
	   String url;
	   String schemes[] = {"hxxp://", "", "http:"};
	   String authorities[] = {"www.google.com", "www.amazon.com", "oregonstate.edu"};
	   
	   UrlValidator val = new UrlValidator();
	   
	   for (int i = 0; i < 3; i++){
		   for (int j = 0; j < 3; j++){
			   url = schemes[i] + authorities[j];
			   if (val.isValid(url)){
				   System.out.println("failure: url is valid - " + url);
		       } else {
		           System.out.println("success: url is invalid - " + url);
			   }
		   }
	   }
   }
   
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
	   System.out.println("\n----- Starting Programming based Tests -----");
	   String url;
	   String schemes[] = {"http://", "https://", "ftp://", "hxxp://", "", "http:"};
	   String authorities[] = {"www.google.com", "www.amazon.com", "oregonstate.edu"};
	   
	   UrlValidator val = new UrlValidator();
	   
	   for (int i = 0; i < 6; i++){
		   for (int j = 0; j < 3; j++){
			   url = schemes[i] + authorities[j];
			   if (val.isValid(url)){
				   System.out.println("url is valid - " + url);
		       } else {
		           System.out.println("url is invalid - " + url);
			   }
		   }
	   }
   }
   


}
