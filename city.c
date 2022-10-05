   #include<stdio.h>
   int main()
   {
       char city[][100]=
       {
           "Mumbai",
           "Pune",
           "Chennai",
           "Kolkata",
          "Delhi",
          "Agartala"
      };
  
      int i;
  
      for(i=0; i<=6;i++)
      {
      printf("%s\n",city[i]);
      sleep(1);
      }
      return 0;
  }
  
