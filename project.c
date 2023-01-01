 /* HERE THIS PROJECT IS MAINLY FOR CUSTOMER BILLING SYSTEM 
     IN WHICH CUSTOMER CAN BUY THINGS ACCORDING TO THE PRICE OF OF THE STORE 
	 IF DISCOUNT IS POSSIBLE THEN MAY BE GIVEN TO CUSTOMER
	 AND AT LAST HIS/HER BILL WILL BE DISPAYED */

    /* BUT HERE IS AN ADDITIONAL OPTION THAT THE ADMINISTRATOR CAN CHECK THIS STORE 
	   INFORMATION */

 # include <stdio.h>
 # include <stdlib.h>
 # include <string.h>
 # include <conio.h>
 # include <ctype.h>

 struct admin
 {
      char id[20];
      char name[40];
      int quantity;
      int price;
 }admin,admin_array[40];

  struct customer
 {
      char id[20];
      char name[40];
      int quantity;
      int price;
 }cus_array[40];

 int n = 8;
 int ci= 0;
 int new();
 int display();
 int edit();
 int  purchase();
 int bill();

 int main()
 {
   int ch2;

   //system("color  37");
   system("color  47");
    int choice , i,pess;
    char password[8] , ch;
    char pass[10] = "admin";
    printf("             _______________________________________________________\n");
    printf("            |                                                       | \n");
    printf("            |            WELCOME TO GLOCERY STORE                   | \n ");                 
    printf("           |_______________________________________________________|\n");
     
    
   q :printf("\n             1.Administration\n");
   printf("             2. Customer\n");
   printf("             3.Exit\n");
   printf("Enter your choice:");
   scanf("%d",&choice);

   switch (choice)
   {
   case 1:
    system("cls");
  
      printf("\nEnter password:\n");
       for ( i = 0; i < 5; i++)
       {
         ch = getch();                     // process for checking password for admin
         password[i] = ch;
         ch = '*';
         printf("%c",ch);
       }
       password[i] = '\0';
       
       //printf("%s   %s",pass,password);

       if (strcmp(password , pass) != 0)
       {
          printf("\nYour password is wrong.\n");
          printf("Press 1 if you want to continue:\n");
          scanf("%d",&pess);
          if (pess == 1)
          {
            goto q;
          }
          
       }

       else
       {
       printf("\n");
       system("pause");                               // display menu for administrator
       printf("\nyour access is granted\n");
     f:  printf("1.Add new item:\n");
       printf("2.Delete or modify:\n");
       printf("3.Display present data:\n");
       printf("4.For display of start menu\n");
       printf("\n         *************Enter your choice*************\n");
       scanf("%d",&choice);
       system("cls");
       switch (choice)
       {
        
       case 1:
           new();
            goto f;
           break;

        case 2:
           edit();
           goto f;
            break;

       case 3:
          display();
          goto f;
        break;

       case 4:
          goto q;
        break;
       
       default:
       printf("\n***************your choice is wrong***************");
        break;

       }

       }
        break;

      case 2:
      system("cls");
     
      printf("\n***************** Welcome to Glocery store as Customer ****************\n");

     cb:   printf("\n1.Display of store items:");
        printf("\n2.For purchasing:");
        printf("\n3.Display of customer bill:");
        printf("\nEnter your choice:");
        scanf("%d",&ch2);

        switch (ch2)
        {
        case 1:
        system("cls");
            display();
            goto cb;
          break;

       case 2:
       system("cls");
              purchase();
              goto cb;
        break;

        case 3:
        system("cls");
              bill();
          break;
        
        default:
        printf("You enter wrong choice:");
          break;
        }

   
   default:
    break;
    }

    return 0;
 }                                 //  for enter new item in store

 int new()
 {
   n++;
   int a;
    FILE *f1;
    f1 = fopen("store.txt","a");
    //fscanf(f1,"%d",&a);              // for number of records in file already
    //printf("%d",a);  
   printf("Enter id of item:");
   scanf("%s",admin.id);
  
   printf("Enter name of item:");
   scanf("%s",admin.name);
    printf("%s",admin.name);
   printf("Enter quantity you want to add:");
   scanf("%d",&admin.quantity);
   printf("Enter price per pack & kg:");
   scanf("%d",&admin.price);
   //printf("%d",admin.price);
    //printf(f1,"\n");
   fprintf(f1,"\n%s \t %s \t  %d \t %d",admin.id,admin.name,admin.quantity,admin.price);
    fclose(f1);
   system("pause");
   
 }

 int display()                   //  for display of store items to administrator
 {
   FILE *f1;
   f1 = fopen("store.txt","r");
    printf("               product-id------ --product name-------product-Quantity--------price-per-pack\n");
    for (int i = 0; i < n; i++)
    {
      fscanf(f1,"%s  %s   %d   %d ",admin_array[i].id,admin_array[i].name,&admin_array[i].quantity,&admin_array[i].price);
     
      printf("               %s \t \t      %s \t   \t   %d  \t\t  %d \n",admin_array[i].id,admin_array[i].name,admin_array[i].quantity,admin_array[i].price);
    }
    fclose(f1);
   system("pause");
 }

  int edit()
  {                              //  this option is for administrator to edit in store items
    int cpy = n;
    int flag = 0;
    char delid[40];
    FILE *f1;
   f1 = fopen("store.txt","r");
   FILE *fd;
   fd = fopen("duplicate.txt","w");
   printf("\nEnter ID of product to delete:\n");
   scanf("%s",delid);
   //printf("%s",delid);

   for (int i = 0; i < cpy; i++)
   {
      fscanf(f1,"%s",admin.id);
       if (strcmp(admin.id , delid) != 0)
       {
      
       fscanf(f1," %s \t  %d   \t %d",admin.name,&admin.quantity,&admin.price);
       fprintf(fd,"%s   \t  %s \t  %d   \t %d\n",admin.id,admin.name,admin.quantity,admin.price);
      // printf("%s   \t  %s \t  %d   \t %d\n",admin.id,admin.name,admin.quantity,admin.price);

       }
       else
       {
        flag = 1;
         fscanf(f1," %s \t  %d   \t %d",admin.name,&admin.quantity,&admin.price);
         n--;
       }
   }

   if (flag == 0)
   {
      printf("\nNo such item is founded in store:\n");
   }
   
   fclose(f1);
   fclose(fd);
    remove("store.txt");
    rename("duplicate.txt","store.txt");
     

  }

   int purchase()
   {
    int found = 0;                //   function for the purchase of items for customers
    char goodname[40];
    int cquan;
     FILE *f1;
     f1 = fopen("store.txt","r");
    //  FILE *fd;
    //  fd = fopen("duplicate.txt","w");
     FILE *fc;
     fc = fopen("customer.txt","w");
   p:  printf("Enter the name of product:");
     scanf("%s",goodname);
    
     for (int i = 0; i < n; i++)
     {
     
      fscanf(f1,"%s  \t  %s  \t %d    \t %d",admin.id,admin.name,&admin.quantity,&admin.price);

       if (strcmp(goodname , admin.name) == 0)
       {
        found = 1;
          printf("Enter quantity:");
          scanf("%d",&cquan);
          if (cquan <= admin.quantity)
          {
            int h;
            admin.quantity = admin.quantity - cquan;
             strcpy(cus_array[ci].id,admin.id);
             //printf("%s",cus_array[ci].id);
             strcpy(cus_array[ci].name ,admin.name);
             cus_array[ci].quantity = cquan;
             cus_array[ci].price = (cquan * admin.price);
             ci++;
             printf("\nEnter 1 if you want to shop more:\n");
             scanf("%d",&h);
             if (h == 1)
             {
                goto p;
             }
             else
             break;
             
          }
          else
          {
          printf("\nSorry given product available in less quantity:\n");
            
          }

      }

    //  else
    //  {
    //     fprintf(fd,"%s  \t  %s  \t %d    \t %d\n",admin.id,admin.name,admin.quantity,admin.price);
    //          continue;
    //  }
    //        fprintf(fd,"%s  \t  %s  \t %d    \t %d\n",admin.id,admin.name,admin.quantity,admin.price);

     }

     if (found == 0)
     {
       printf("\nSorry given item is not available in store:\n");
     }
     
     
        fclose(f1);
        fclose(fc);
       // fclose(fd);
      //   remove("store.txt");
      //  rename("duplicate.txt","store.txt");
        system("pause");
        system("cls");
   }

  int bill()
  {                                         //   display of customer bill
    int total = 0;
     FILE *f1;
     f1 = fopen("store.txt","r");
     FILE *fc;
     fc = fopen("customer.txt","w");
     if (fc == NULL)
     {
       printf("\nSorry you do not purchase any item:\n");
     }
     
      printf("               product-id------ --product name-------product-Quantity--------price\n");
    for (int i = 0; i < ci; i++)
    {
       fprintf(fc,"%s    \t  %s   \t  %d    \t  %d\n",cus_array[i].id,cus_array[i].name,cus_array[i].quantity,cus_array[i].price);
       
      printf("                 %s    \t  \t   %s   \t      \t %d \t\t\t  %d\n",cus_array[i].id,cus_array[i].name,cus_array[i].quantity,cus_array[i].price);
    }
    for (int i = 0; i < ci; i++)
    {
       total = total + cus_array[i].price;
    }
    
    
    printf("\n");
    printf("                   _____________________________________________________\n");
    printf("                  |                                                     |\n");
    printf("                  |      TOTAL  PRICE          |       %d                |\n",total);
    printf("                  |_____________________________________________________|\n");
    
    printf("\n\n         *******************  THANK YOU FOR COMMING HERE  **********************\n");
   
  

  }