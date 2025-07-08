#include<stdio.h>
struct student
{
	int roll;
	char name[50];
	float marks;
};
struct student students[50];
int count = 0;
int i;
void addstudent()
{
	if(count>50)
	{
		printf("Maximum number of students reached Thank you\n");
	}
	printf("Enter the roll no.");
	scanf("%d",&students[count].roll);
	
	printf("Enter the name ");
	scanf("%s",&students[count].name);
	
	printf("Enter the marks ");
	scanf("%2f",&students[count].marks);
	
	count++;
	printf("Student added succesfully\n");
}
void display()
{
	if(count==0)
	{
		printf("No data found\n");
	}
	for(i=0;i<count;i++)
	{
		printf("Roll no:%d\tName:%s\tMarks:%2f\n",students[i].roll,students[i].name,students[i].marks);
	}
}
void search()
{
    int roll, found = 0;
    printf("Enter the Roll No: ");
    scanf("%d", &roll);

    for(i = 0; i<count; i++)
    {
        if(students[i].roll == roll)
        {
            printf("Student found:\n");
            printf("Roll No: %d\tName: %s\tMarks: %.2f\n", students[i].roll, students[i].name, students[i].marks);
            found = 1;
            break;
        }
    }
    if (found==0)
    {
        printf("Error: Student not found\n");
    }
}
void update()
{
    int roll, found = 0;
    printf("Enter the Roll No to update: ");
    scanf("%d", &roll);

    for(i=0; i<count; i++)
    {
        if(students[i].roll == roll)
        {
            printf("Current data:\n");
            printf("Name: %s\tMarks: %.2f\n", students[i].name, students[i].marks);

            printf("Enter the new name: ");
            scanf(" %s", students[i].name);  

            printf("Enter the new marks: ");
            scanf("%f", &students[i].marks);

            printf("Updated data:\n");
            printf("Name: %s\tMarks: %.2f\n", students[i].name, students[i].marks);

            found = 1;
            break;
        }
    }

    if (found==0)
    {
        printf("Error: Student not found\n");
    }
}
void deletestudent()
{
	int j;
    int roll;
    int found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);
    for(i=0; i<count; i++)
    {
        if(students[i].roll == roll)
        {
            for (j=i;j<count-1;j++)
            {
                students[j] = students[j + 1];
            }
            count--;
            found = 1;
            printf("Student deleted successfully\n");
            break;
        }
    }
    if (found==0)
        printf("Error: Student not found\n");
}
int main()
{
	int s;
	do
	{
		printf("Select the option given below for Student database management\n");
		printf("1.Add Student\n");
		printf("2.Display all information\n");
		printf("3.Search student data\n");
		printf("4.Update the student data\n");
		printf("5.Delete the student data\n");
		printf("6.Exit\n");
		printf("Enter the option");
		scanf("%d",&s);
		switch(s)
		{
			case 1:
			{
				addstudent();
				break;
			}
			case 2:
			{
				display();
				break;
			}
			case 3:
			{
				search();
				break;
			}
			case 4:
			{
				update();
				break;
			}
			case 5:
			{
				deletestudent();
				break;
			}
			case 6:
			{
				printf("Exited succesdfully\n");
				break;
			}
			default:
			{
				printf("\nInvalid option");
			}
		}
	printf("\n\n\n");
	}while(s!=6);
	return 0;
}

