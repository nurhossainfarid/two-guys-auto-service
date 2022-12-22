// declare all header file or dependencies
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>


/* ____________________________________________Create All structure__________________________________________ */
// registration structure
struct Registration {
    char name[20];
    char userName[20];
    char email[20];
    char password[20];
    char phoneNumber[20];
    char address[20];
    char role[10];
} reg;

// service structure
struct Service {
    char name[20];
    char details[50];
    int price;
    char status[7];
    int serviceId;
} services;

// vehicle parts structure
struct VehiclePart {
    char customerName[20];
    char customerEmail[20];
    char customerPhone[20];
    char customerAddress[20];
    char name[20];
    char details[50];
    int price;
    char brand[20];
    int quantity;
    char status[10];
    int partId;
} partSell;

// parts repair structure
struct PartRepair {
    char customerName[20];
    char customerEmail[20];
    char customerPhone[20];
    char customerAddress[20];
    char vehicleType[20];
    char partName[20];
    int repairId;
} repair;

// Appointment structure
struct Appointment {
    char customerName[20];
    char customerEmail[20];
    char customerPhone[20];
    char customerAddress[20];
    char date[10];
    char time[10];
    int appointmentId;
} appointment;

// Vehicle wash
struct VehicleWash {
    char customerName[20];
    char customerEmail[20];
    char customerPhone[20];
    char customerAddress[20];
    char washType[20];
    int washId;
} wash;

// Blogs 
struct Blog {
    char vehicleName[20];
    char description[100];
    int blogId;
} blog;



/* _____________________________________________Register Function____________________________________________ */
// declare register function
registe() {
    FILE *log;
    log = fopen("user.txt", "a");

    printf("User Registration\n");
    // full name
    fflush(stdin);
    printf("\tEnter your full name: ");
    gets(reg.name);
    // user name
    fflush(stdin);
    printf("\tEnter your user name: ");
    gets(reg.userName);
    // email
    fflush(stdin);
    printf("\tEnter your email address: ");
    gets( reg.email);
    // password
    fflush(stdin);
    printf("\tEnter your password: ");
    gets(reg.password);
    // phone number
    fflush(stdin);
    printf("\tEnter your phone number: ");
    gets(reg.phoneNumber);
    // address
    fflush(stdin);
    printf("\tEnter your address: ");
    gets(reg.address);
    // role
    fflush(stdin);
    printf("\tEnter your role must be [user or admin]: ");
    gets(reg.role);
    // write data to file
    fwrite(&reg, sizeof(reg), 1, log);
    // close function
    fclose(log);

    // login
    printf("\nNow login with your user name and password\n");
    printf("\nPress any key to continue....");
    getch();
    system("CLS");
    // call login function
    login();
};

/* _____________________________________________Login Function____________________________________________ */
// declare login function
login() {
    char email[20], password[20];
    FILE *log;
    log = fopen("user.txt", "r");
    printf("User Login\n");
    // take user name and password from user
    fflush(stdin);
    printf("\tEnter your email address: ");
    gets(email);
    fflush(stdin);
    printf("\tEnter your password: ");
    gets(password);

    // check user name and password is valid or not
    
    while(fread(&reg, sizeof(reg), 1, log)) {
        if (strcmp(email, reg.email) == 0 && strcmp(password, reg.password) == 0)
        {
            printf("\n%s login successful\n", reg.role);
            if ( strcmp("user", reg.role) == 0)
            {
                allFeatures(reg.role);
            }else if(strcmp("admin", reg.role) == 0){
                allFeatures(reg.role);
            }
            
        } else {
            printf("Please Enter your correct user name and password");
        }
        
    }
    fclose(log);
}

// two guys auto service all features
int allFeatures(char role[20]) {
    printf("\n\t\t\tTwo Guys Auto Service All Features\n\n");
    int cho;
    printf("\tPress\n\t1.Service Items\n\t2.Parts Repair\n\t3.Part Selling\n\t4.Appointment\n\t5.Vehicle Wash\n\t6.Blogs\n\t7.Exit\n");
    scanf("%d", &cho);
    switch(cho){
        case 1:
            printf("Handle All service items\n");
            // call handleServiceItems function
            handleServiceItems(reg.role);  
        break;
        case 2: 
            printf("Handle All booked part repair\n");
            // call handlePartRepair function
            handlePartRepair(reg.role);  
        break;
        
        case 3:
            printf("Handle Part Selling\n");
            // call handlePartSelling function
            handlePartSelling(reg.role);
        break;
        case 4:
            printf("Handle Appointment\n");
            // call handlePartSelling function
            handleAppointment(reg.role);
        break;
        case 5:
            printf("Handle Vehicle Wash\n");
            // call handleVehicleWash function
            handleVehicleWash(reg.role);
        break;
        case 6:
            printf("Handle Blogs\n");
            // call handleBlogs function
            handleBlogs(reg.role);
        break;
        case 7:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
            break;
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
        break;
    }
}





/* _____________________________________________Service Part____________________________________________ */

// service crud operations
// create a service
int serviceCreate(char role[20]){
    char another,cho;
    FILE *serviceItems;
    do{
        printf("\t\t\t\t=======Add Service Item=======\n\n"); 
        // open file 
        serviceItems = fopen("serviceItems.txt", "a");

        // take info from admin
        fflush(stdin);
        printf("Service Name: ");
        gets(services.name);
        fflush(stdin);
        printf("Service Details: ");
        gets(services.details);
        fflush(stdin);
        printf("Service price: ");
        scanf("%d", &services.price);
        fflush(stdin);
        printf("status: ");
        gets(services.status);
        fflush(stdin);
        printf("Service id: ");
        scanf("%d", &services.serviceId);

        if(serviceItems==NULL){
            fprintf(stderr,"can't open file");
        }else{
            printf("\n\n\t\t\tRecord stored successfully\n\n");
        }

        // write data to file
        fwrite(&services, sizeof(services), 1, serviceItems);
        // close file
        fclose(serviceItems);

        // add another service item
        printf("You want to add another service item?(y/n) : ");
        scanf("%s",&another);
    } while (another == 'y'||another== 'Y' );
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
        // call handleServiceItems function
        handleServiceItems(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
};
// Read All Service items
int allServiceRead(char role[20]){
    FILE *serviceItems;
    serviceItems=fopen("serviceItems.txt","r");
    
    printf("\t\t\t\t=======Service Items RECORD=======\n\n\n");
      
    if(serviceItems=='\0'){
        
        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }
        
        while(fread(&services,sizeof(services),1,serviceItems)){
        printf("\n\t\t\t\t Service Name    : %s",services.name);
        printf("\n\t\t\t\t Service Details : %s",services.details);
        printf("\n\t\t\t\t Price           : %d",services.price);
        printf("\n\t\t\t\t Status          : %s",services.status);
        printf("\n\t\t\t\t ServiceId      : %d",services.serviceId);
        printf("\n\t\t\t\t ________________________________\n");
      
         }
        fclose(serviceItems);
        int cho;
        printf("\n1.Back To Previous...\n2.Exit\n");
        scanf("%d",&cho);
        if (cho==1)
        {
            // call handleServiceItems function
            handleServiceItems(role);
        } else if(cho==2) {
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        }
        getch();
      
}
// search one service
int searchOneService(char role[20]) {
    FILE *serviceItems;
    int sId,found=0;
     
    serviceItems = fopen("serviceItems.txt","r");
    printf("\t\t\t\t=======SEARCH A SERVICE=======\n\n\n");
    printf("\t\t\tEnter the service id : ");
    scanf("%d",&sId);

    while(fread(&services,sizeof(services),1,serviceItems)){
        if(services.serviceId==sId){
           
        found=1;
        printf("\n\n\t\t\tService Name  : %s",services.name);
        printf("\n\t\t\tService Details : %s",services.details);
        printf("\n\t\t\tPrice           : %d",services.price);
        printf("\n\t\t\tStatus          : %s",services.status);
        printf("\n\t\t\tService Id      : %d",services.serviceId);
        printf("\n\t\t\t______________________________________\n");
  
        }   
    }
     
    if(!found){
       printf("\n\t\t\tRecord not found\n");
    } 
    fclose(serviceItems);
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
        // call handleServiceItems function
        handleServiceItems(role);
    } else if(cho==2) {
        exit(0);
    }
    getch();
}
// update Service
int updateServiceById(char role[20]) {
    FILE *serviceItems, *tempService;
    int sId,found=0;
     
    serviceItems = fopen("serviceItems.txt","r+");
    tempService = fopen("tempService.txt", "a+");
    printf("\t\t\t\t=======SEARCH A SERVICE=======\n\n\n");
    printf("\t\t\tEnter the service id : ");
    scanf("%d",&sId);

    while(fread(&services,sizeof(services),1,serviceItems)){
        if(services.serviceId==sId){          
            found=1;
            fflush(stdin);
            printf("Update Service Name: ");
            gets(services.name);
            fflush(stdin);
            printf("Update Service Details: ");
            gets(services.details);
            fflush(stdin);
            printf("Update Service price: ");
            scanf("%d", &services.price);
            fflush(stdin);
            printf("Update status: ");
            gets(services.status);

            // write data to file
            fwrite(&services, sizeof(services), 1, tempService);
            
        } else if(services.serviceId!=sId) {
            fwrite(&services, sizeof(services), 1, tempService);
        }
    }

    fclose(serviceItems);
    fclose(tempService);
     
    if(!found){
       printf("\n\t\t\tService Could not update!\n");
    }
    if(found) {
        remove("tempService.txt");
        rename("tempService.txt","serviceItems.txt");
        printf("\n\t\t\tService updated Successfully!\n");
    }
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
        // call handleServiceItems function
        handleServiceItems(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// delete service by serviceId
int deleteService(char role[20]) {
    FILE *serviceItems,*serviceItem;
    int sId, found=0;
    
    printf("\t\t\t\t=======DELETE SERVICE ITEM=======\n\n\n");
    serviceItems=fopen("serviceItems.txt","r");
    serviceItem=fopen("temp.txt","w");
    printf("\t\t\t\tEnter the service id : ");
    scanf("%d",&sId);
    if(serviceItems=='\0'){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }
    
    while(fread(&services,sizeof(services),1,serviceItems)){
        if(services.serviceId == sId){ 
            found=1;
        }else{
           fwrite(&services,sizeof(services),1,serviceItem);
        }
  
    }
    fclose(serviceItems);
    fclose(serviceItem);

    if(!found){
        printf("\n\t\t\t\tRecord not found\n");
    }
    if(found){ 
      remove("serviceItems.txt");
      rename("temp.txt","serviceItems.txt");
      
      printf("\n\t\t\t\tRecord deleted successfully\n");
    }
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
        // call handleServiceItems function
        handleServiceItems(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// Handle Services Items 
int handleServiceItems(char role[10]) {
    // select service operations
    if (strcmp("admin", role) == 0)
    {
        int select;
        printf("\tPress\n\t\t1.Create Service\n\t\t2.Read Service\n\t\t3.Search One Service\n\t\t4.Update Service\n\t\t5.Delete Service\n\t\t6.Exit\n\t\t7.Back To Previous\n");
        scanf("%d", &select);
        switch(select){
            case 1:
                serviceCreate(role);
            break;
            case 2:
                allServiceRead(role);
                getch();
            break;
            
            case 3:
                searchOneService(role);
                getch();
            break;
    
            case 4:
                updateServiceById(role);
                getch();
            break;
            case 5: 
                deleteService(role);
                getch();
                
            break;
            case 6:
                printf("\n\t\t\t\tThank you, for used this software.\n\n");
                exit(0);
            break;
            case 7:
                allFeatures(role);
            break;
            
            default :
                getch();
                printf("\n\t\t\t\t\tEnter a valid number\n\n");
                printf("\t\t\t\tPress any key to continue.......");
                getch();
            break;
            }
    } else if(strcmp("user", role) == 0) {
        int select;
        printf("\tPress\n\t\t1.Read All Service\n\t\t2.Search One Service\n\t\t3.Exit\n");
        scanf("%d", &select);
        switch(select){
            case 1:
                allServiceRead(role);
                getch();
            break;
            
            case 2:
                searchOneService(role);
                getch();
            break;
    
            case 3:
                printf("\n\t\t\t\tThank you, for used this software.\n\n");
                exit(0);
            break;
            
            default :
                getch();
                printf("\n\t\t\t\t\tEnter a valid number\n\n");
                printf("\t\t\t\tPress any key to continue.......");
                getch();
            break;
        }
    }   
}



/* _____________________________________________Parts Repair____________________________________________ */

// Repair crud operations
// Book part repair
int bookPartRepair(char role[10]){
    char another;
    FILE *partsRepair;
    do{
        printf("\t\t\t\t=======Book Part Repair=======\n\n"); 
        // open file 
        partsRepair = fopen("partsRepair.txt", "a");

        // take info from admin
        fflush(stdin);
        printf("Customer Name: ");
        gets(repair.customerName);
        fflush(stdin);
        printf("Customer Email: ");
        gets(repair.customerEmail);
        fflush(stdin);
        printf("Customer Phone: ");
        gets(repair.customerPhone);
        fflush(stdin);
        printf("Customer Address: ");
        gets(repair.customerAddress);
        fflush(stdin);
        printf("Vehicle Type: ");
        gets(repair.vehicleType);
        fflush(stdin);
        printf("Part Name: ");
        gets(repair.partName);
        printf("Booking Id: ");
        scanf("%d",&repair.repairId);

        if(partsRepair==NULL){
            fprintf(stderr,"can't open file");
        }else{
            printf("\n\n\t\tPart Repair Booking stored successfully\n\n");
        }

        // write data to file
        fwrite(&repair, sizeof(repair), 1, partsRepair);
        // close file
        fclose(partsRepair);

        // add another service item
        printf("You want to add another part repair booking item?(y/n) : ");
        scanf("%s",&another);
    } while (another == 'y'||another== 'Y' );
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
        // call handlePartRepair function
        handlePartRepair(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
};

// Read All booked part repair
int readAllBookedPartRepair(char role[10]){
    FILE *partsRepair;
    partsRepair=fopen("partsRepair.txt","r");
    
     printf("\t\t\t\t=======Part Repair Booking History=======\n\n\n");
      
    if(partsRepair=='\0'){
        
        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("\t\t\t\tBooking History :\n");
        printf("\t\t\t\t___________\n\n");
    }
        
        while(fread(&repair,sizeof(repair),1,partsRepair)){
        printf("\n\t\t\t\t Customer Name    : %s",repair.customerName);
        printf("\n\t\t\t\t Customer Email   : %s",repair.customerEmail);
        printf("\n\t\t\t\t Customer Phone   : %s",repair.customerPhone);
        printf("\n\t\t\t\t Customer Address : %s",repair.customerAddress);
        printf("\n\t\t\t\t Vehicle Type     : %s",repair.vehicleType);
        printf("\n\t\t\t\t Part Name        : %s",repair.partName);
        printf("\n\t\t\t\t Repair Id        : %d",repair.repairId);
        printf("\n\t\t\t\t ________________________________\n");
      
         }
    fclose(partsRepair);
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
        // call handlePartRepair function
        handlePartRepair(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// search one repair
int readOneBookedPartRepair(char role[10]) {
    FILE *partsRepair;
    int sId, found=0;
     
    partsRepair = fopen("partsRepair.txt","r");
    printf("\t\t\t\t=======SEARCH A Part Repair=======\n\n\n");
    fflush(stdin);
    printf("\t\t\tEnter the service id : ");
    scanf("%d",&sId);

    while(fread(&repair,sizeof(repair),1,partsRepair)){
        if(repair.repairId==sId){
           
        found=1;
        printf("\n\t\t\t\t Customer Name    : %s",repair.customerName);
        printf("\n\t\t\t\t Customer Email   : %s",repair.customerEmail);
        printf("\n\t\t\t\t Customer Phone   : %s",repair.customerPhone);
        printf("\n\t\t\t\t Customer Address : %s",repair.customerAddress);
        printf("\n\t\t\t\t Vehicle Type     : %s",repair.vehicleType);
        printf("\n\t\t\t\t Part Name        : %s",repair.partName);
        printf("\n\t\t\t\t Repair Id        : %d",repair.repairId);
        printf("\n\t\t\t______________________________________\n");

        }   
    }
     
    if(!found){
       printf("\n\t\t\tRecord not found\n");
    } 
    fclose(partsRepair);
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
        // call handlePartRepair function
        handlePartRepair(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// delete repair by repair
int deleteBookedPartRepair(char role[10]) {
    FILE *partsRepair,*partRepair;
    int sId, found=0;
    
    printf("\t\t\t\t=======DELETE Booked Part Repair=======\n\n\n");
    partsRepair=fopen("partsRepair.txt","r");
    partRepair=fopen("temp2.txt","w");
    printf("\t\t\t\tEnter the Repair id : ");
    scanf("%d",&sId);
    if(partsRepair=='\0'){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }
    
    while(fread(&repair,sizeof(repair),1,partsRepair)){
        if(repair.repairId == sId){ 
            found=1;
        }else{
           fwrite(&repair,sizeof(repair),1,partRepair);
        }
  
    }
    fclose(partsRepair);
    fclose(partRepair);

    if(!found){
        printf("\n\t\t\t\tRecord not found\n");
    }
    if(found){ 
      remove("partsRepair.txt");
      rename("temp2.txt","partsRepair.txt");
      
      printf("\n\t\t\t\tRepair deleted successfully\n");
    }
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
        // call handlePartRepair function
        handlePartRepair(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// Handle Part Repair
int handlePartRepair(char role[20]) {
    if (strcmp("admin", role) == 0)
    {
    // select book repair operations
    int select;
    printf("\tPress\n\t\t1.Book Part Repair\n\t\t2.Read All Booked Repair\n\t\t3.Search One Booked Repair\n\t\t4.Update Repair\n\t\t5.Delete Booked Repair\n\t\t6.Exit\n\t\t7.Back To Previous\n");
    scanf("%d", &select);
    switch(select){
        case 1:
            bookPartRepair(role);
            getch();
        break;
        case 2:
            readAllBookedPartRepair(role);
            getch();
        break;
        
        case 3:
            readOneBookedPartRepair(role);
            getch();
        break;
  
        case 4:
            // update parts
        break;
        case 5: 
            deleteBookedPartRepair(role);
            getch();
        break;
        case 6:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        break;
        case 7:
            allFeatures(role);
        break;
        
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
         break;
        }
    } else if(strcmp("user", role) == 0) {
    int select;
    printf("\tPress\n\t\t1.Book Part Repair\n\t\t2.Search Your Booked Repair\n\t\t3.Exit\n");
    scanf("%d", &select);
    switch(select){
        case 1:
            bookPartRepair(role);
            getch();
        break;
        
        case 2:
            readOneBookedPartRepair(role);
            getch();
        break;
        case 3:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        break;
        
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
         break;
        }
    } 
}



/* _____________________________________________Parts Selling____________________________________________ */

// parts selling crud operations
// order part
int orderPart(char role[10]){
    char another;
    FILE *partsSelling;
    do{
        printf("\t\t\t\t=======Order Part=======\n\n"); 
        // open file 
        partsSelling = fopen("partsSelling.txt", "a");

        // take info from admin
        fflush(stdin);
        printf("Customer Name: ");
        gets(partSell.customerName);
        fflush(stdin);
        printf("Customer Email: ");
        gets(partSell.customerEmail);
        fflush(stdin);
        printf("Customer Phone: ");
        gets(partSell.customerPhone);
        fflush(stdin);
        printf("Customer Address: ");
        gets(partSell.customerAddress);
        fflush(stdin);
        printf("Part Name : ");
        gets(partSell.name);
        fflush(stdin);
        printf("Part Details : ");
        gets(partSell.details);
        fflush(stdin);
        printf("Part Price : ");
        scanf("%d",&partSell.price);
        fflush(stdin);
        printf("Brand Name : ");
        gets(partSell.brand);
        fflush(stdin);
        printf("Part Quantity : ");
        scanf("%d",&partSell.quantity);
        fflush(stdin);
        printf("Status : ");
        scanf("%s",&partSell.status);
        fflush(stdin);
        printf("Part Id: ");
        scanf("%d",&partSell.partId);

        if(partsSelling==NULL){
            fprintf(stderr,"can't open file");
        }else{
            printf("\n\n\t\tPart Repair Booking stored successfully\n\n");
        }

        // write data to file
        fwrite(&partSell, sizeof(partSell), 1, partsSelling);
        // close file
        fclose(partsSelling);

        // add another service item
        printf("You want to add another part?(y/n) : ");
        scanf("%s",&another);
    } while (another == 'y'||another== 'Y' );
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handlePartSelling function
    handlePartSelling(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
};

// Read All booked part
int readAllOrderedPart(char role[10]){
    FILE *partsSelling;
    partsSelling=fopen("partsSelling.txt","r");
    
     printf("\t\t\t\t=======Part History=======\n\n\n");
      
    if(partsSelling=='\0'){
        
        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("\t\t\t\tBooking History :\n");
        printf("\t\t\t\t___________\n\n");
    }
        
        while(fread(&partSell,sizeof(partSell),1,partsSelling)){
        printf("\n\t\t\t\t Customer Name    : %s",partSell.customerName);
        printf("\n\t\t\t\t Customer Email   : %s",partSell.customerEmail);
        printf("\n\t\t\t\t Customer Phone   : %s",partSell.customerPhone);
        printf("\n\t\t\t\t Customer Address : %s",partSell.customerAddress);
        printf("\n\t\t\t\t Part Name        : %s",partSell.name);
        printf("\n\t\t\t\t Part Details     : %s",partSell.details);
        printf("\n\t\t\t\t Part Price       : %d",partSell.price);
        printf("\n\t\t\t\t Brand Name       : %s",partSell.brand);
        printf("\n\t\t\t\t Part Quantity    : %d",partSell.quantity);
        printf("\n\t\t\t\t Status           : %s",partSell.status);
        printf("\n\t\t\t\t Part Id          : %d",partSell.partId);
        printf("\n\t\t\t\t ________________________________\n");
      
         }
        fclose(partsSelling);
        int cho;
        printf("\n1.Back To Previous...\n2.Exit\n");
        scanf("%d",&cho);
        if (cho==1)
        {
        // call handlePartSelling function
        handlePartSelling(role);
        } else if(cho==2) {
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        }
        getch();
      
}

// search one part order
int readOneOrderedPart(char role[10]) {
    FILE *partsSelling;
    int pId, found=0;
     
    partsSelling = fopen("partsSelling.txt","r");
    printf("\t\t\t\t=======SEARCH A SERVICE=======\n\n\n");
    fflush(stdin);
    printf("\t\t\tEnter the service id : ");
    scanf("%d",&pId);

    while(fread(&partSell,sizeof(partSell),1,partsSelling)){
        if(partSell.partId==pId){
           
        found=1;
        printf("\n\t\t\t\t Customer Name    : %s",partSell.customerName);
        printf("\n\t\t\t\t Customer Email   : %s",partSell.customerEmail);
        printf("\n\t\t\t\t Customer Phone   : %s",partSell.customerPhone);
        printf("\n\t\t\t\t Customer Address : %s",partSell.customerAddress);
        printf("\n\t\t\t\t Part Name        : %s",partSell.name);
        printf("\n\t\t\t\t Part Details     : %s",partSell.details);
        printf("\n\t\t\t\t Part Price       : %d",partSell.price);
        printf("\n\t\t\t\t Brand Name       : %s",partSell.brand);
        printf("\n\t\t\t\t Part Quantity    : %d",partSell.quantity);
        printf("\n\t\t\t\t Status           : %s",partSell.status);
        printf("\n\t\t\t\t Part Id          : %d",partSell.partId);
        printf("\n\t\t\t______________________________________\n");

        }   
    }
     
    if(!found){
       printf("\n\t\t\tRecord not found\n");
    } 
    fclose(partsSelling);
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handlePartSelling function
    handlePartSelling(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// delete order  by orderId
int deleteOrderedPart(char role[10]) {
    FILE *partsSelling,*partSelling;
    int pId, found=0;
    
    printf("\t\t\t\t=======DELETE Booked Part Repair=======\n\n\n");
    partsSelling=fopen("partsSelling.txt","r");
    partSelling=fopen("temp3.txt","w");
    printf("\t\t\t\tEnter the Repair id : ");
    scanf("%d",&pId);
    if(partsSelling=='\0'){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }
    
    while(fread(&partSell,sizeof(partSell),1,partsSelling)){
        if(partSell.partId == pId){ 
            found=1;
        }else{
           fwrite(&partSell,sizeof(partSell),1,partSelling);
        }
  
    }
    fclose(partsSelling);
    fclose(partSelling);

    if(!found){
        printf("\n\t\t\t\tPart not found\n");
    }
    if(found){ 
      remove("partsSelling.txt");
      rename("temp3.txt","partsSelling.txt");
      
      printf("\n\t\t\t\tPart deleted successfully\n");
    }
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handlePartSelling function
    handlePartSelling(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// Handle Services Items 
int handlePartSelling(char role[10]) {
    if (strcmp("admin", role) == 0)
    {
    // select part operations
    int select;
    printf("\tPress\n\t\t1. Order Part\n\t\t2. Read All Part\n\t\t3. Search One Part\n\t\t4. Update A Part\n\t\t5. Delete A Part\n\t\t6.Exit\n\t\t7.Back To Previous\n");
    scanf("%d", &select);
    switch(select){
        case 1:
            orderPart(role);
            getch();
        break;
        case 2:
            readAllOrderedPart(role);
            getch();
        break;
        
        case 3:
            readOneOrderedPart(role);
            getch();
        break;
  
        case 4:
            // update parts
        break;
        case 5: 
            deleteOrderedPart(role);
            getch();
        break;
        case 6:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        break;
        case 7:
            allFeatures(role);
        break;
        
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
         break;
        }
    } else if(strcmp("user", role) == 0) {
    int select;
    printf("Press\n\t\t1.Order Part\n\t\t2.Search Your Ordered Part\n\t\t3.Exit\n");
    scanf("%d", &select);
    switch(select){
        case 1:
            orderPart(role);
            getch();
        break;
        case 2:
            readOneOrderedPart(role);
            getch();
        break;
        case 3:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        break;
        
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
         break;
        }
    } 
}



/* _____________________________________________Appointment____________________________________________ */

// Appointment crud operations
// Make Appointment
int makeAppointment(char role[10]){
    char another;
    FILE *makeAppointment;
    do{
        printf("\t\t\t\t=======Order Part=======\n\n"); 
        // open file 
        makeAppointment = fopen("makeAppointment.txt", "a");

        // take info from admin
        fflush(stdin);
        printf("Customer Name: ");
        gets(appointment.customerName);
        fflush(stdin);
        printf("Customer Email: ");
        gets(appointment.customerEmail);
        fflush(stdin);
        printf("Customer Phone: ");
        gets(appointment.customerPhone);
        fflush(stdin);
        printf("Customer Address: ");
        gets(appointment.customerAddress);
        fflush(stdin);
        printf("Appointment Date : ");
        gets(appointment.date);
        fflush(stdin);
        printf("Appointment Time : ");
        gets(appointment.time);
        fflush(stdin);
        printf("Appointment Id: ");
        scanf("%d",&appointment.appointmentId);

        if(makeAppointment==NULL){
            fprintf(stderr,"can't open file");
        }else{
            printf("\n\n\t\tAppointment stored successfully\n\n");
        }

        // write data to file
        fwrite(&appointment, sizeof(appointment), 1, makeAppointment);
        // close file
        fclose(makeAppointment);

        // add another service item
        printf("You want to add another part?(y/n) : ");
        scanf("%s",&another);
    } while (another == 'y'||another== 'Y' );
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handleVehicleWash function
    handleAppointment(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
};

// Read All booked part repair
int readAllAppointment(char role[10]){
    FILE *makeAppointment;
    makeAppointment=fopen("makeAppointment.txt","r");
    
     printf("\t\t\t\t=======Appointment History=======\n\n\n");
      
    if(makeAppointment=='\0'){
        
        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("\t\t\t\Appointment History :\n");
        printf("\t\t\t\t___________\n\n");
    }
        
        while(fread(&appointment,sizeof(appointment),1,makeAppointment)){
        printf("\n\t\t\t\t Customer Name    : %s",appointment.customerName);
        printf("\n\t\t\t\t Customer Email   : %s",appointment.customerEmail);
        printf("\n\t\t\t\t Customer Phone   : %s",appointment.customerPhone);
        printf("\n\t\t\t\t Customer Address : %s",appointment.customerAddress);
        printf("\n\t\t\t\t Appointment Date : %s",appointment.date);
        printf("\n\t\t\t\t Appointment Time : %s",appointment.time);
        printf("\n\t\t\t\t Appointment Id   : %d",appointment.appointmentId);
        printf("\n\t\t\t\t ________________________________\n");
      
         }
        fclose(makeAppointment);
        int cho;
        printf("\n1.Back To Previous...\n2.Exit\n");
        scanf("%d",&cho);
        if (cho==1)
        {
        // call handleVehicleWash function
        handleAppointment(role);
        } else if(cho==2) {
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        }
        getch();
      
}

// search one service
int readOneAppointment(char role[10]) {
    FILE *makeAppointment;
    int apId, found=0;
     
    makeAppointment = fopen("makeAppointment.txt","r");
    printf("\t\t\t\t=======SEARCH Vehicle Wash=======\n\n\n");
    fflush(stdin);
    printf("\t\t\tEnter the vehicle wash id : ");
    scanf("%d",&apId);

    while(fread(&appointment,sizeof(appointment),1,makeAppointment)){
        if(appointment.appointmentId==apId){
           
        found=1;
        printf("\n\t\t\t\t Customer Name    : %s",appointment.customerName);
        printf("\n\t\t\t\t Customer Email   : %s",appointment.customerEmail);
        printf("\n\t\t\t\t Customer Phone   : %s",appointment.customerPhone);
        printf("\n\t\t\t\t Customer Address : %s",appointment.customerAddress);
        printf("\n\t\t\t\t Appointment Date : %s",appointment.date);
        printf("\n\t\t\t\t Appointment Time : %s",appointment.time);
        printf("\n\t\t\t\t Appointment Id   : %d",appointment.appointmentId);
        printf("\n\t\t\t______________________________________\n");

        }   
    }
     
    if(!found){
       printf("\n\t\t\tRecord not found\n");
    } 
    fclose(makeAppointment);
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handleVehicleWash function
    handleAppointment(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// delete service by serviceId
int deleteAppointment(char role[10]) {
    FILE *makeAppointment,*makeAppointment2;
    int apId, found=0;
    
    printf("\t\t\t\t=======DELETE Appointment=======\n\n\n");
    makeAppointment=fopen("makeAppointment.txt","r");
    makeAppointment2=fopen("temp3.txt","w");
    printf("\t\t\t\tEnter the appointment id : ");
    scanf("%d",&apId);
    if(makeAppointment=='\0'){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }
    
    while(fread(&appointment,sizeof(appointment),1,makeAppointment)){
        if(appointment.appointmentId == apId){ 
            found=1;
        }else{
           fwrite(&appointment,sizeof(appointment),1,makeAppointment);
        }
  
    }
    fclose(makeAppointment);
    fclose(makeAppointment2);

    if(!found){
        printf("\n\t\t\t\tAppointment not found\n");
    }
    if(found){ 
      remove("makeAppointment.txt");
      rename("temp3.txt","makeAppointment.txt");
      
      printf("\n\t\t\t\tAppointment deleted successfully\n");
    }
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handleVehicleWash  function
    handleAppointment(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// Handle vehicle Wash
int handleAppointment(char role[10]) {
    if (strcmp("admin", role) == 0)
    {
    // select part operations
    int select;
    printf("\tPress\n\t\t1.Make Appointment\n\t\t2.Read All Appointment\n\t\t3.Search One Appointment\n\t\t4. Update A Appointment\n\t\t5.Delete A Appointment\n\t\t6.Exit\n\t\t7.Back To Previous\n");
    scanf("%d", &select);
    switch(select){
        case 1:
            makeAppointment(role);
            getch();
        break;
        case 2:
            readAllAppointment(role);
            getch();
        break;
        
        case 3:
            readOneAppointment(role);
            getch();
        break;
  
        case 4:
            // update parts
        break;
        case 5: 
            deleteAppointment(role);
            getch();
        break;
        case 6:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        break;
        case 7:
            allFeatures(role);
        break;
        
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
         break;
        }
    } else if(strcmp("user", role) == 0) {
    int select;
    printf("Press\n\t\t1.Make Appointment\n\t\t2.Search Your Appointment\n\t\t3.Exit\n");
    scanf("%d", &select);
    switch(select){
        case 1:
            makeAppointment(role);
            getch();
        break;
        case 2:
            readOneAppointment(role);
            getch();
        break;
        case 3:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        break;
        
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
         break;
        }
    } 
}



/* _____________________________________________Vehicle Wash____________________________________________ */

// wash crud operations
// vehicle wash
int vehicleWash(char role[10]){
    char another;
    FILE *vehicleWash;
    do{
        printf("\t\t\t\t=======Order Part=======\n\n"); 
        // open file 
        vehicleWash = fopen("vehicleWash.txt", "a");

        // take info from admin
        fflush(stdin);
        printf("Customer Name: ");
        gets(wash.customerName);
        fflush(stdin);
        printf("Customer Email: ");
        gets(wash.customerEmail);
        fflush(stdin);
        printf("Customer Phone: ");
        gets(wash.customerPhone);
        fflush(stdin);
        printf("Customer Address: ");
        gets(wash.customerAddress);
        fflush(stdin);
        printf("Wash Type : ");
        gets(wash.washType);
        fflush(stdin);
        printf("Part Id: ");
        scanf("%d",&wash.washId);

        if(vehicleWash==NULL){
            fprintf(stderr,"can't open file");
        }else{
            printf("\n\n\t\tPart Repair Booking stored successfully\n\n");
        }

        // write data to file
        fwrite(&wash, sizeof(wash), 1, vehicleWash);
        // close file
        fclose(vehicleWash);

        // add another service item
        printf("You want to add another part?(y/n) : ");
        scanf("%s",&another);
    } while (another == 'y'||another== 'Y' );
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handleVehicleWash function
    handleVehicleWash(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
};

// Read All booked wash
int readAllVehicleWash(char role[10]){
    FILE *vehicleWash;
    vehicleWash=fopen("vehicleWash.txt","r");
    
     printf("\t\t\t\t=======Vehicle Wash History=======\n\n\n");
      
    if(vehicleWash=='\0'){
        
        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("\t\t\t\Vehicle wash History :\n");
        printf("\t\t\t\t___________\n\n");
    }
        
        while(fread(&wash,sizeof(wash),1,vehicleWash)){
        printf("\n\t\t\t\t Customer Name    : %s",wash.customerName);
        printf("\n\t\t\t\t Customer Email   : %s",wash.customerEmail);
        printf("\n\t\t\t\t Customer Phone   : %s",wash.customerPhone);
        printf("\n\t\t\t\t Customer Address : %s",wash.customerAddress);
        printf("\n\t\t\t\t Wash Type        : %s",wash.washType);
        printf("\n\t\t\t\t Wash Id          : %d",wash.washId);
        printf("\n\t\t\t\t ________________________________\n");
      
         }
        fclose(vehicleWash);
        int cho;
        printf("\n1.Back To Previous...\n2.Exit\n");
        scanf("%d",&cho);
        if (cho==1)
        {
        // call handleVehicleWash function
        handleVehicleWash(role);
        } else if(cho==2) {
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        }
        getch();
      
}

// search one wash
int readOneVehicleWash(char role[10]) {
    FILE *vehicleWash;
    int vwId, found=0;
     
    vehicleWash = fopen("vehicleWash.txt","r");
    printf("\t\t\t\t=======SEARCH Vehicle Wash=======\n\n\n");
    fflush(stdin);
    printf("\t\t\tEnter the vehicle wash id : ");
    scanf("%d",&vwId);

    while(fread(&wash,sizeof(wash),1,vehicleWash)){
        if(wash.washId==vwId){
           
        found=1;
        printf("\n\t\t\t\t Customer Name    : %s",wash.customerName);
        printf("\n\t\t\t\t Customer Email   : %s",wash.customerEmail);
        printf("\n\t\t\t\t Customer Phone   : %s",wash.customerPhone);
        printf("\n\t\t\t\t Customer Address : %s",wash.customerAddress);
        printf("\n\t\t\t\t Wash Type        : %s",wash.washType);
        printf("\n\t\t\t\t Wash Id          : %d",wash.washId);
        printf("\n\t\t\t______________________________________\n");

        }   
    }
     
    if(!found){
       printf("\n\t\t\tRecord not found\n");
    } 
    fclose(vehicleWash);
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handleVehicleWash function
    handleVehicleWash(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// delete wash by washId
int deleteVehicleWash(char role[10]) {
    FILE *vehicleWash,*vehicleWash2;
    int pId, found=0;
    
    printf("\t\t\t\t=======DELETE Vehicle Wash=======\n\n\n");
    vehicleWash=fopen("vehicleWash.txt","r");
    vehicleWash2=fopen("temp3.txt","w");
    printf("\t\t\t\tEnter the Repair id : ");
    scanf("%d",&pId);
    if(vehicleWash=='\0'){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }
    
    while(fread(&wash,sizeof(wash),1,vehicleWash)){
        if(wash.washId == pId){ 
            found=1;
        }else{
           fwrite(&wash,sizeof(wash),1,vehicleWash2);
        }
  
    }
    fclose(vehicleWash);
    fclose(vehicleWash2);

    if(!found){
        printf("\n\t\t\t\tPart not found\n");
    }
    if(found){ 
      remove("vehicleWash.txt");
      rename("temp3.txt","vehicleWash.txt");
      
      printf("\n\t\t\t\tVehicle Wash deleted successfully\n");
    }
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handleVehicleWash  function
    handleVehicleWash(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}


// Handle vehicle Wash
int handleVehicleWash(char role[10]) {
    if (strcmp("admin", role) == 0)
    {
    // select part operations
    int select;
    printf("Press\n\t\t1.Vehicle Wash\n\t\t2.Read All Vehicle Wash\n\t\t3.Search One Vehicle Wash\n\t\t4. Update A Vehicle Wash\n5. Delete A Vehicle Wash\n6.Exit\n\t\t7.Back To Previous\n");
    scanf("%d", &select);
    switch(select){
        case 1:
            vehicleWash(role);
            getch();
        break;
        case 2:
            readAllVehicleWash(role);
            getch();
        break;
        
        case 3:
            readOneVehicleWash(role);
            getch();
        break;
  
        case 4:
            // update parts
        break;
        case 5: 
            deleteVehicleWash(role);
            getch();
        break;
        case 6:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        break;
        case 7:
            allFeatures(role);
        break;
        
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
         break;
        }
    } else if(strcmp("user", role) == 0) {
    int select;
    printf("Press\n\t\t1.Order Part\n\t\t2.Search Your Ordered Part\n\t\t3.Exit\n");
    scanf("%d", &select);
    switch(select){
        case 1:
            orderPart(role);
            getch();
        break;
        case 2:
            readOneOrderedPart(role);
            getch();
        break;
        case 3:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        break;
        
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
         break;
        }
    } 
}



/* _____________________________________________Blogs____________________________________________ */

// Blogs crud operations
// create Blog
int createBlog(char role[10]){
    char another;
    FILE *blogs;
    do{
        printf("\t\t\t\t=======Blogs=======\n\n"); 
        // open file 
        blogs = fopen("blogs.txt", "a");

        // take info from admin
        fflush(stdin);
        printf("Vehicle Name: ");
        gets(blog.vehicleName);
        fflush(stdin);
        printf("Vehicle Details: ");
        gets(blog.description);
        fflush(stdin);
        printf("Part Id: ");
        scanf("%d",&blog.blogId);

        if(blogs==NULL){
            fprintf(stderr,"can't open file");
        }else{
            printf("\n\n\t\tBlog stored successfully\n\n");
        }

        // write data to file
        fwrite(&blog, sizeof(blog), 1, blogs);
        // close file
        fclose(blogs);

        // add another service item
        printf("You want to add another part?(y/n) : ");
        scanf("%s",&another);
    } while (another == 'y'||another== 'Y' );
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handleVehicleWash function
    handleBlogs(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
};

// Read All blogs
int readAllBlogs(char role[10]){
    FILE *blogs;
    blogs=fopen("blogs.txt","r");
    
     printf("\t\t\t\t=======Blogs History=======\n\n\n");
      
    if(blogs=='\0'){
        
        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("\t\t\t\Blogs :\n");
        printf("\t\t\t\t___________\n\n");
    }
        
        while(fread(&blog,sizeof(blog),1,blogs)){
        printf("\n\t\t\t\t Vehicle Name    : %s",blog.vehicleName);
        printf("\n\t\t\t\t Customer Email  : %s",blog.description);
        printf("\n\t\t\t\t Blog Id         : %d",blog.blogId);
        printf("\n\t\t\t\t ________________________________\n");
      
         }
        fclose(blogs);
        int cho;
        printf("\n1.Back To Previous...\n2.Exit\n");
        scanf("%d",&cho);
        if (cho==1)
        {
        // call handleVehicleWash function
        handleBlogs(role);
        } else if(cho==2) {
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        }
        getch();
      
}

// search one blog
int readOneBlog(char role[10]) {
    FILE *blogs;
    int bId, found=0;
     
    blogs = fopen("blogs.txt","r");
    printf("\t\t\t\t=======SEARCH Vehicle Wash=======\n\n\n");
    fflush(stdin);
    printf("\t\t\tEnter the vehicle wash id : ");
    scanf("%d",&bId);

    while(fread(&wash,sizeof(wash),1,blogs)){
        if(wash.washId==bId){
           
        found=1;
        printf("\n\t\t\t\t Vehicle Name    : %s",blog.vehicleName);
        printf("\n\t\t\t\t Customer Email  : %s",blog.description);
        printf("\n\t\t\t\t Blog Id         : %d",blog.blogId);
        printf("\n\t\t\t______________________________________\n");

        }   
    }
     
    if(!found){
       printf("\n\t\t\tRecord not found\n");
    } 
    fclose(blogs);
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handleVehicleWash function
    handleBlogs(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// delete blog by blogId
int deleteBlog(char role[10]) {
    FILE *blogs,*blogs2;
    int bId, found=0;
    
    printf("\t\t\t\t=======DELETE Vehicle Wash=======\n\n\n");
    blogs=fopen("blogs.txt","r");
    blogs2=fopen("blogs2.txt","w");
    printf("\t\t\t\tEnter the blog id : ");
    scanf("%d",&bId);
    if(blogs=='\0'){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }
    
    while(fread(&blog,sizeof(blog),1,blogs)){
        if(blog.blogId == bId){ 
            found=1;
        }else{
           fwrite(&blog,sizeof(blog),1,blogs2);
        }
  
    }
    fclose(blogs);
    fclose(blogs2);

    if(!found){
        printf("\n\t\t\t\Blog not found\n");
    }
    if(found){ 
      remove("blogs.txt");
      rename("blogs2.txt","blogs.txt");
      
      printf("\n\t\t\t\tBlog deleted successfully\n");
    }
    int cho;
    printf("\n1.Back To Previous...\n2.Exit\n");
    scanf("%d",&cho);
    if (cho==1)
    {
    // call handleVehicleWash  function
    handleBlogs(role);
    } else if(cho==2) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    getch();
}

// Handle blogs
int handleBlogs(char role[10]) {
    if (strcmp("admin", role) == 0)
    {
    // select part operations
    int select;
    printf("Press\n\t\t1.Create Blogs\n\t\t2.Read All Blogs\n\t\t3.Search One Blog\n\t\t4. Update A Blog\n5. Delete A Blog\n6.Exit\n\t\t7.Back To Previous\n");
    scanf("%d", &select);
    switch(select){
        case 1:
            createBlog(role);
            getch();
        break;
        case 2:
            readAllBlogs(role);
            getch();
        break;
        
        case 3:
            readOneBlog(role);
            getch();
        break;
  
        case 4:
            // update parts
        break;
        case 5: 
            deleteBlog(role);
            getch();
        break;
        case 6:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        break;
        case 7:
            allFeatures(role);
        break;
        
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
         break;
        }
    } else if(strcmp("user", role) == 0) {
    int select;
    printf("Press\n\t\t1.Read All Blogs\n\t\t2.Search A Blog\n\t\t3.Exit\n");
    scanf("%d", &select);
    switch(select){
        case 1:
            readAllBlogs(role);
            getch();
        break;
        case 2:
            readOneBlog(role);
            getch();
        break;
        case 3:
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(0);
        break;
        
        default :
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
         break;
        }
    } 
}



/* _____________________________________________Main Function____________________________________________ */
// start main function
int main() {
    int cho;
    printf("Press\n1.Registration\n2.Login\n3.Exit\n");
    scanf("%d", &cho);
    if (cho == 1)
    {
        system("CLS");
        registe();
    } else if (cho == 2)
    {
        system("CLS");
        login();
    } else if (cho == 3) {
        printf("\n\t\t\t\tThank you, for used this software.\n\n");
        exit(0);
    }
    
}