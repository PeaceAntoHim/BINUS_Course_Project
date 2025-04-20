#include <stdio.h>
#include <string.h>

struct Employee {
    int employee_id;
    char name[20];
    int salary;
};

struct Organisation {
    char organisation_name[20];
    char org_number[20];
	
struct Employee emp;
};

// Driver code
int main() {
// Structure variable
struct Organisation org;
	
// structure
printf("Besar struktur organisasi : %ld\n",
		sizeof(org));
	
org.emp.employee_id = 201;
strcpy(org.emp.name, "Frans Sebastian");
org.emp.salary = 8000000;
strcpy(org.organisation_name,
		"Binus University");
strcpy(org.org_number, "2502121162");
	
// Printing the details
printf("Nama Organisasi : %s\n",
		org.organisation_name);
printf("Nomer Organisasi : %s\n",
		org.org_number);
printf("Id Karyawan : %d\n",
		org.emp.employee_id);
printf("Nama Karyawan : %s\n",
		org.emp.name);
printf("Gaji Karyawan : %d\n",
		org.emp.salary);
}
