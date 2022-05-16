#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();
struct date
    {
    int day,month,year;
    };
struct registration
   {
    char name[60];
    int vehicle_no,age;
    char address[60];
    char nationality[30];
    double phone;
    char vehicle_type[10];
    float amt;
    struct date dob;
    struct date deposit;

    }add,upd,check,rem,ric,dev,sear,dele,taka;




int main()
{
    char pass[11],password[11]="bangladesh";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\n");

                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");

                    system("cls");
                    goto login_try;}

        }
        return 0;
}



void menu()
{
    int choice;
    system("cls");
    //system("color 9");
    printf("\n\n\t\t\tRESIDENTIAL AREA VEHICLE MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t WELCOME TO THE MAIN MENU ");
    printf("\n\n\t\t1.For Residential area vehicles\n\t\t2.For Residential wellfares\n\t\3.For Residential area map\n\t\tEnter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:menu2();
        break;
        case 2:menu3();
        break;
        case 3:map();
        break;
    }


}



void menu2()
{
     int choice;
    system("cls");
    //system("color 9");
    printf("\n\n\t\tRESIDENTIAL AREA VEHICLE MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t THE MENU OF RESIDENTIAL VEHICLES");
    printf("\n\n\t\t1.Register new vehicle\n\t\t2.Update information of registered vehicle\n\t\t3.Check the details of registered vehicle\n\t\t4.Removing vehicle registration\n\t\t5.View vehicle's list\n\t\t6.Exit\n\t\tEnter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc1();
        break;
        case 2:edit1();
        break;
        case 3:details_vehicle();
        break;
        case 4:erase();
        break;
        case 5:view_list1();
        break;
        case 6:close();
        break;

    }
}


void menu3()
{
     int choice;
    system("cls");
    //system("color 9");
    printf("\n\n\t\tRESIDENTIAL AREA VEHICLE MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t THE MENU OF RESIDENTIAL WELLFARE");
    printf("\n\n\t\t1.Create new ID\n\t\t2.For adding base fare\n\t\t3.Check the details of registered rickshaw pullers\n\t\t4.Removing existing ID\n\t\t5.View Vehicle drivers list\n\t\t6.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc_rickshaw();
        break;
        case 2:base_fare();
        break;
        case 3:details_rickshaw();
        break;
        case 4:erase_rickshaw();
        break;
        case 5:list_rickshaw();
        break;
        case 6:close();
        break;

    }

}


void new_acc1()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.txt","a+");
    account_no:
    system("cls");
    printf("\t\t\t ADD RECORD  ");
    printf("\n\n\nEnter today's date(dd/mm/yyyy): ");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\nEnter the vehicle number: ");
    scanf("%d",&check.vehicle_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %d %lf %s %d/%d/%d",&add.vehicle_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.nationality,&add.phone,add.vehicle_type,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
        if (check.vehicle_no==add.vehicle_no)
            {printf("Vehicle is already registered!");

                goto account_no;

            }
    }
    add.vehicle_no=check.vehicle_no;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the nationality:");
    scanf("%s",add.nationality);
    printf("\nEnter the phone number: ");
    fflush(stdin);
    scanf("%lf",&add.phone);
    fflush(stdin);
    printf("\nType of vehicle:");
    scanf("%s",add.vehicle_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s  %d/%d/%d",add.vehicle_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.nationality,add.phone,add.vehicle_type,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nVehicle registered successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}



void edit1()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.vehicle_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d",&add.vehicle_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.nationality,&add.phone,add.vehicle_type,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
        if (add.vehicle_no==upd.vehicle_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d\n",add.vehicle_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,upd.address,add.nationality,add.phone,add.vehicle_type,add.deposit.day,add.deposit.month,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d\n",add.vehicle_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.nationality,upd.phone,add.vehicle_type,add.deposit.day,add.deposit.month,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d\n",add.vehicle_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.nationality,add.phone,add.vehicle_type,add.deposit.day,add.deposit.month,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit1();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}



void details_vehicle()
{
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.txt","r");
    printf("Do you want to check by\n1.Vehicle no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the vehicle number:");
        scanf("%d",&check.vehicle_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d",&add.vehicle_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.nationality,&add.phone,add.vehicle_type,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
        {
            if(add.vehicle_no==check.vehicle_no)
            {   system("cls");
                test=1;

                printf("\nVEHICLE NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nNationality:%s \nPhone number:%.0lf \nType Of vehicle:%s \nDate Of Registration:%d/%d/%d\n\n",add.vehicle_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.nationality,add.phone,
                add.vehicle_type,add.deposit.day,add.deposit.month,add.deposit.year);

            }

            }
        }

    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d",&add.vehicle_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.nationality,&add.phone,add.vehicle_type,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nVehicle No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nNationality:%s \nPhone number:%.0lf \nType Of Vehicle:%s \nDate Of Registration:%d/%d/%d\n\n",add.vehicle_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.nationality,add.phone,
                add.vehicle_type,add.deposit.day,add.deposit.month,add.deposit.year);

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    details_vehicle();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}




void erase()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter the vehicle no. you want to delete:");
    scanf("%d",&rem.vehicle_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d",&add.vehicle_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.nationality,&add.phone,add.vehicle_type,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
   {
        if(add.vehicle_no!=rem.vehicle_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d\n",add.vehicle_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.nationality,add.phone,add.vehicle_type,add.deposit.day,add.deposit.month,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}




void view_list1()
{
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d",&add.vehicle_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.nationality,&add.phone,add.vehicle_type,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.vehicle_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}




void new_acc_rickshaw()

{
    int choice;
    FILE *ptr;

    ptr=fopen("recordric.txt","a+");
    account_no:
    system("cls");
    printf("\t\t\t\ ADD RECORD ");
    printf("\n\n\nEnter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d",&ric.deposit.day,&ric.deposit.month,&ric.deposit.year);
    printf("\nEnter the ID number:");
    scanf("%d",&sear.vehicle_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&ric.vehicle_no,ric.name,&ric.dob.day,&ric.dob.month,&ric.dob.year,&ric.age,ric.address,ric.nationality,&ric.phone,ric.vehicle_type,&ric.amt,&ric.deposit.day,&ric.deposit.month,&ric.deposit.year)!=EOF)
    {
        if (sear.vehicle_no==ric.vehicle_no)
            {printf("ID no. already in use!");
                goto account_no;
            }
    }
    ric.vehicle_no=sear.vehicle_no;

    printf("\nEnter the name:");
     fflush(stdin);
    scanf("%[^\n]s",ric.name);
    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&ric.dob.day,&ric.dob.month,&ric.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&ric.age);
    printf("\nEnter the address:");
     fflush(stdin);
    scanf("%s",ric.address);
    printf("\nEnter the nationality:");
     fflush(stdin);
    scanf("%s",ric.nationality);
    printf("\nEnter the phone number: ");
     fflush(stdin);
    scanf("%lf",&ric.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&ric.amt);
    printf("\nType of vehicle:");
     fflush(stdin);
    scanf("%s",ric.vehicle_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",ric.vehicle_no,ric.name,ric.dob.day,ric.dob.month,ric.dob.year,ric.age,ric.address,ric.nationality,ric.phone,ric.vehicle_type,ric.amt,ric.deposit.day,ric.deposit.month,ric.deposit.year);


    fclose(ptr);
    printf("\nVehicle Registered Successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}




void base_fare()
{
     int choice,test=0;
    FILE *old,*newrec;
    old=fopen("recordric.txt","r");
    newrec=fopen("newric.txt","w");

        printf("Enter the ID number of the rickshawpuller:");
    scanf("%d",&taka.vehicle_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&ric.vehicle_no,ric.name,&ric.dob.day,&ric.dob.month,&ric.dob.year,&ric.age,ric.address,ric.nationality,&ric.phone,ric.vehicle_type,&ric.amt,&ric.deposit.day,&ric.deposit.month,&ric.deposit.year)!=EOF)
   {

            if(ric.vehicle_no==taka.vehicle_no)
            {
                test == 1;

                    printf("Enter the amount you want to add:$ ");
                    scanf("%f",&taka.amt);
                    ric.amt+=taka.amt;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",ric.vehicle_no,ric.name,ric.dob.day,ric.dob.month,ric.dob.year,ric.age,ric.address,ric.nationality,ric.phone,ric.vehicle_type,ric.amt,ric.deposit.day,ric.deposit.month,ric.deposit.year);
                    printf("\n\nAdded successfully!");
            }



            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",ric.vehicle_no,ric.name,ric.dob.day,ric.dob.month,ric.dob.year,ric.age,ric.address,ric.nationality,ric.phone,ric.vehicle_type,ric.amt,ric.deposit.day,ric.deposit.month,ric.deposit.year);
            }
    }

   fclose(old);
   fclose(newrec);
   remove("recordric.txt");
   rename("newric.txt","recordric.txt");
   if(test!=1)
   {
      printf("\n\nRecord not found!!");
      basefare_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        base_fare();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto basefare_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}




void details_rickshaw()
{
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("recordric.txt","r");
    printf("Do you want to check by\n1.ID no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the ID number:");
        scanf("%d",&sear.vehicle_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&ric.vehicle_no,ric.name,&ric.dob.day,&ric.dob.month,&ric.dob.year,&ric.age,ric.address,ric.nationality,&ric.phone,ric.vehicle_type,&ric.amt,&ric.deposit.day,&ric.deposit.month,&ric.deposit.year)!=EOF)
        {
            if(ric.vehicle_no==sear.vehicle_no)
            {   system("cls");
                test=1;

                printf("\nID NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nNationality:%s \nPhone number:%.0lf \nType Of Vehicle:%s \nAmount:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",ric.vehicle_no,ric.name,ric.dob.day,ric.dob.month,ric.dob.year,ric.age,ric.address,ric.nationality,ric.phone,ric.vehicle_type,ric.amt,ric.deposit.day,ric.deposit.month,ric.deposit.year);

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&sear.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&ric.vehicle_no,ric.name,&ric.dob.day,&ric.dob.month,&ric.dob.year,&ric.age,ric.address,ric.nationality,&ric.phone,ric.vehicle_type,&ric.amt,&ric.deposit.day,&ric.deposit.month,&ric.deposit.year)!=EOF)
        {
            if(strcmpi(ric.name,sear.name)==0)
            {
                system("cls");
                test=1;
                printf("\nID No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nNationality:%s \nPhone number:%.0lf \nType Of Vehicle:%s \nAmount:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",ric.vehicle_no,ric.name,ric.dob.day,ric.dob.month,ric.dob.year,ric.age,ric.address,ric.nationality,ric.phone,ric.vehicle_type,ric.amt,ric.deposit.day,ric.deposit.month,ric.deposit.year);

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    details_rickshaw();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}




void erase_rickshaw()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("recordric.txt","r");
    newrec=fopen("newric.txt","w");
    printf("Enter the ID no. of the Rickshawpuller you want to delete:");
    scanf("%d",&dele.vehicle_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&ric.vehicle_no,ric.name,&ric.dob.day,&ric.dob.month,&ric.dob.year,&ric.age,ric.address,ric.nationality,&ric.phone,ric.vehicle_type,&ric.amt,&ric.deposit.day,&ric.deposit.month,&ric.deposit.year)!=EOF)
   {
        if(ric.vehicle_no!=dele.vehicle_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",ric.vehicle_no,ric.name,ric.dob.day,ric.dob.month,ric.dob.year,ric.age,ric.address,ric.nationality,ric.phone,ric.vehicle_type,ric.amt,ric.deposit.day,ric.deposit.month,ric.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("recordric.txt");
   rename("newric.txt","recordric.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            eraseric_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase_rickshaw();
                else
                    {printf("\nInvalid!\a");
                    goto eraseric_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}




void list_rickshaw()
{
    FILE *view;
    view=fopen("recordric.txt","r");
    int test=0;
    system("cls");
    printf("\nID NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&ric.vehicle_no,ric.name,&ric.dob.day,&ric.dob.month,&ric.dob.year,&ric.age,ric.address,ric.nationality,&ric.phone,ric.vehicle_type,&ric.amt,&ric.deposit.day,&ric.deposit.month,&ric.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",ric.vehicle_no,ric.name,ric.address,ric.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}



int map()
{
    printf("\n\n\n\t\t\xdb\xdb\xdb\xdb                                       \xdb\xdb\xdb\xdb                                              \xdb\xdb\xdb\xdb\xdb");
   	printf("\n\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\xdb  [rd-1]         \xdb                 \xdb                   \xdb              \xdb                       \xdb\xdb\xdb\n");
	printf("\t\t\xdb                 \xdb                 \xdb                   \xdb M O S Q U E  \xdb                       \xdb\xdb\xdb\n");
	printf("\t\t\xdb                 \xdb                 \xdb                   \xdb              \xdb                       \xdb\xdb\xdb\n");
	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb                   \xdb              \xdb                       \xdb\xdb\xdb\n");
	printf("\t\t\xdb  [rd-2]        \xdb                 \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb                       \xdb\xdb\xdb\n");
	printf("\t\t\xdb                \xdb                            \xdb                       \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\xdb  P A R K I N G \xdb                            \xdb                         \xdb                       \xdb\xdb\n");
	printf("\t\t\xdb      ZONE      \xdb     H O S P I T A L        \xdb   R E S T A U R E N T   \xdb     O F F I C E       \xdb\xdb\n");
	printf("\t\t\xdb       01       \xdb                            \xdb                         \xdb                       \xdb\xdb\n");
	printf("\t\t\xdb                \xdb                            \xdb                         \xdb                       \xdb\xdb\n");
	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\xdb  [rd-3]            \xdb                                \xdb                                 \xdb       \xdb\xdb\n");
	printf("\t\t\xdb                    \xdb                                \xdb                                 \xdb       \xdb\xdb\n");
	printf("\t\t\xdb                    \xdb    P A R K I N G   Z O N E     \xdb                                 \xdb       \xdb\xdb\n");
	printf("\t\t\xdb                    \xdb                                \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\xdb U N I V E R S I T Y\xdb              02                \xdb                              \xdb       \xdb  \xdb\xdb\n");
	printf("\t\t\xdb                    \xdb                                \xdb                              \xdb       \xdb  \xdb\xdb\n");
	printf("\t\t\xdb                    \xdb                                \xdb                              \xdb       \xdb  \xdb\xdb\n");
	printf("\t\t\xdb                    \xdb                                \xdb                              \xdb       \xdb  \xdb\xdb\n");
	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\t\t        \xdb  [rd-4]         \xdb                 \xdb                   \xdb              \xdb                       \xdb\xdb\xdb\n");
	printf("\t\t\xdb                 \xdb                 \xdb                   \xdb              \xdb     P A R K I N G     \xdb\xdb\xdb\n");
	printf("\t\t\xdb                 \xdb                 \xdb                   \xdb              \xdb      Z O N E 03       \xdb\xdb\xdb\n");
	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb                   \xdb              \xdb                       \xdb\xdb\xdb\n");
	printf("\t\t\xdb  [rd-5]        \xdb                 \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb                       \xdb\xdb\xdb\n");
	printf("\t\t\xdb                \xdb                            \xdb                       \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\xdb                \xdb                            \xdb      S C H O O L        \xdb                       \xdb\xdb\n");
	printf("\t\t\xdb                \xdb                            \xdb          &              \xdb                       \xdb\xdb\n");
	printf("\t\t\xdb                \xdb                            \xdb     C O L L E G E       \xdb                       \xdb\xdb\n");
	printf("\t\t\xdb                \xdb                            \xdb                         \xdb                       \xdb\xdb\n");
	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\xdb\xdb\xdb\xdb                                       \xdb\xdb\xdb\xdb                                              \xdb\xdb\xdb\xdb\xdb");


return 0;
}



void close()
{
    printf("\n\n\n\nThis Project is created by Nobin Bokhtiar!");
}



