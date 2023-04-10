#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define _GNU_SOURCE
void print_magic_info(char *elf_header);
void print_class_info(char *elf_header);
void print_data_info(char *elf_header);
void print_version_info(char *elf_header);
void print_osabi_info(char *elf_header);
char *get_osabi_info(char *elf_header);
void print_type_info(char *elf_header);
void print_entry_info(char *elf_header);
void print_title(char *title);
/**
 * main - displays the information contained it the ELF header
 * at the start of the ELF file.
 * @argc: the number of arguments passed to the main function.
 * @argv: array of strings passed to the main function.
 * Return: Always 0.
 * 1 if incorrect number of arguments.
 * 2 if file open failed.
 * 3 if read file failed.
 * 98 if magic is not matched by string.
 */
int main(int argc, char **argv)
{
	int file_des, bytes_read;
	Elf32_Ehdr buffer;

	if (argc != 2)
	{
		dprintf(2, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	file_des = open(argv[1], O_RDONLY);
	if (file_des == -1)
	{
		dprintf(2, "Error: Can't open file\n");
		exit(98);
	}
	bytes_read = read(file_des, &buffer, sizeof(buffer));
	if (bytes_read != sizeof(buffer))
	{
		dprintf(2, "Error: Can't read file\n");
		exit(98);
	}
	if (is_invalid_elf(&buffer))
	{
		dprintf(2, "Error: Not an elf file");
		exit (98);
	}

	printf("ELF Header:\n");
	print_magic_info(buffer);
	print_class_info(buffer);
	print_data_info(buffer);
	print_version_info(buffer);
	print_osabi_info(buffer);
	print_type_info(buffer);
	print_entry_info(buffer);

	close(file_des);
	return (0);
}

void is_invalid_elf(Elf64_Ehdr *buffer)
{
	if (buffer.e_ident[EI_MAG0] != ELFMAG0 || buffer.e_ident[EI_MAG1] != ELFMAG1
			|| buffer.e_ident[EI_MAG2] != ELFMAG2 || buffer.e_ident[EI_MAG3] != ELFMAG3)
		return (1);
	return (0);
}

/**
 * print_magic_info - prints the magic information of the
 * elf header file.
 * @elf_header: elf header information.
 */
void print_magic_info(char *elf_header)
{
	int index = 0;

	printf("  Magic:  ");
	while (index < 16)
		printf("%02x ", elf_header[index++]);
	printf("\n");
}

/**
 * print_class_info - prints the class information of the
 * elf header file.
 * @elf_header: elf header information.
 */
void print_class_info(char *elf_header)
{
	print_title("Class:");
	if (elf_header[4] == 1)
		printf("ELF32\n");
	else if (elf_header[4] == 2)
		printf("ELF64\n");
	else
		printf("<unknown: %02hx>", elf_header[4]);
}

/**
 * print_data_info - prints the data information of the
 * elf header file.
 * @elf_header: the elf header information.
 */
void print_data_info(char *elf_header)
{
	print_title("Data:");

	if (elf_header[5] == 1)
		printf("2's compliment, little endian\n");
	else if (elf_header[5] == 2)
		printf("2's compliment, big endian\n");
	else
		printf("<unknown: %02hx>", elf_header[5]);
}

/**
 * print_version_info - prints the version information of the
 * elf header file.
 * @elf_header: the elf header information.
 */
void print_version_info(char *elf_header)
{
	print_title("Version:");
	if (elf_header[6] > EV_CURRENT)
		printf("49 <unknown %%lx>");
	else
	{
		printf("%i", elf_header[6]);
		if (elf_header[6] != EV_CURRENT)
			printf("\n");
		else
			printf(" (current)\n");
	}
}

/**
 * print_osabi_info - prints the OS/ABI information of the
 * elf header file.
 * @elf_header: the elf header information.
 */
void print_osabi_info(char *elf_header)
{
	char *osabi_info;

	print_title("OS/ABI:");
	printf("UNIX - ");

	osabi_info = get_osabi_info(elf_header);

	if (osabi_info != NULL)
		printf("%s\n", osabi_info);
	else
		printf("<unknown: %02x>\n", elf_header[7]);
	printf("  %-35s%d\n", "ABI Version:", elf_header[8]);
}
/**
 * get_osabi_info - returns the correct osabi stirng.
 * @elf_header: a elf header file.
 */
char *get_osabi_info(char *elf_header)
{
	switch (elf_header[7])
	{
		case 0:
			return ("System V");
		case 1:
			return ("HP-UX");
		case 2:
			return ("NetBSD");
		case 3:
			return ("Linux");
		case 4:
			return ("GNU Hurd");
		case 6:
			return ("Solaris");
		case 7:
			return ("AIX");
		case 8:
			return ("IRIX");
		case 9:
			return ("FeeBSD");
		case 10:
			return ("Tru64");
		case 11:
			return ("Novell Modesto");
		case 12:
			return ("OpenBSD");
		case 13:
			return ("Open Vms");
		case 14:
			return ("NonStop Kernel");
		case 15:
			return ("AROS");
		case 16:
			return ("Fenix OS");
		case 17:
			return ("CloudABI");
		default:
			return (NULL);
	}
}

/**
 * print_type_info - prints the type information of the
 * elf header file.
 * @elf_header: the elf header information.
 */
void print_type_info(char *elf_header)
{
	int index = 0;

	print_title("Type:");
	index = elf_header[5] == 1 ? 16 : 17;

	switch (elf_header[index])
	{
		case 1:
			printf("REL (Relocatable file)\n");
			break;
		case 2:
			printf("EXEC (Executable file)\n");
			break;
		case 3:
			printf("DYN (Shared object file)\n");
			break;
		case 4:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown>: %02x%02x\n", elf_header[16], elf_header[17]);
	}
}

/**
 * print_entry_info - prints the entry information of the
 * elf header file.
 * @elf_header: the elf header information.
 */
void print_entry_info(char *elf_header)
{
	int index, tag;
	char i;

	print_title("Entry point address:");
	i = elf_header[4] + '0';

	if (i == '1')
	{
		tag = 26;
		printf("80");
		index = tag;
		while (index >= 22)
		{
			if (elf_header[index] > 0)
				printf("%x", elf_header[index]);
			else if (elf_header[index] < 0)
				printf("%x", 256 + elf_header[index]);
			index--;
		}
		if (elf_header[7] == 6)
			printf("00");
	}
	else if (i == '2')
	{
		tag = 26;
		index = tag;
		while (elf_header[index] > 23)
		{
			if (elf_header[index] >= 0)
				printf("%02x", elf_header[index]);
			else if (elf_header[index] < 0)
				printf("%02x", elf_header[index] + 256);
			index--;
		}
	}
	printf("\n");
}

/**
 * print_title - prints a string.
 * @title: a string.
 */
void print_title(char *title)
{
	printf("  %-35s", title);
}
