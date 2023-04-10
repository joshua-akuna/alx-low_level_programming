#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <elf.h>

void print_class_info(unsigned char *e_ident);
void print_data_info(unsigned char *e_ident);
void print_version_info(unsigned char *e_ident);
void print_magic_info(unsigned char *e_ident);
void print_abi_version_info(unsigned char *e_ident);
void print_osabi_info(unsigned char *e_ident);
void print_type_info(unsigned int e_type, unsigned char *e_ident);
void print_entry_info(unsigned long int e_entry, unsigned char *e_ident);
void close_file_desc(int file_desc);
void validate_elf(unsigned char *e_ident);
void print_elf_header_info(Elf64_Ehdr *header);

/**
 * main - prints specified information about an
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments passed to the main function.
 * @argv: an array of strings passed as arguments.
 * Return: 0 on success.
 * else exit with code 98 if the file is not an ELF
 * file or the function fails.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int file_desc, bytes_read;

	(void) argc;
	file_desc = open(argv[1], O_RDONLY);
	if (file_desc == -1)
	{
		dprintf(2, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_file_desc(file_desc);
		dprintf(2, "Error: malloc failed\n");
		exit(98);
	}
	bytes_read = read(file_desc, header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		close_file_desc(file_desc);
		free(header);
		dprintf(STDERR_FILENO, "Error: Can't read file\n");
		exit(98);
	}

	validate_elf(header->e_ident);
	printf("ELF Header:\n");
	print_elf_header_info(header);
	free(header);
	close_file_desc(file_desc);
	return (0);
}

/**
 * print_elf_header_info - prints all the specified information
 * of the elf header at the start of an ELF file..
 * @header: a pointer to an array containing the information of
 * the elf header.
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
	print_magic_info(header->e_ident);
	print_class_info(header->e_ident);
	print_data_info(header->e_ident);
	print_version_info(header->e_ident);
	print_osabi_info(header->e_ident);
	print_abi_version_info(header->e_ident);
	print_type_info(header->e_type, header->e_ident);
	print_entry_info(header->e_entry, header->e_ident);
}

/**
 * validate_elf - Checks if the argument is a valid ELF file.
 * @e_ident: an array containing the ELF magic numbers.
 */
void validate_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 && e_ident[i] != 'E'
				&& e_ident[i] != 'L' && e_ident[i] != 'F')
		{
			dprintf(2, "Error: Not a valid ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic_info - prints the magic numbers of the ELF header.
 * @e_ident: an array which contains the ELF magic numbers.
 */
void print_magic_info(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class_info - prints the information about the class
 * of the ELF header file.
 * @e_ident: an array containing the ELF header class information..
 */
void print_class_info(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data_info - prints information of the data section
 * of an ELF file header.
 * @e_ident: an array that contains information about the class
 * of the elf file header.
 */
void print_data_info(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version_info - prints details about the version section
 * of the ELF file header.
 * @e_ident: an array that contains information about the
 * ELF file version.
 */
void print_version_info(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi_info - prints the detais of the OS/ABI information
 * of the ELF file header.
 * @e_ident: an array that contains information about
 * the OS/ABI of the ELF file header.
 */
void print_osabi_info(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi_version_info - prints details of the ABI version
 * of the ELF file header argument.
 * @e_ident: an array that stores information of the ELF file
 * ABI version.
 */
void print_abi_version_info(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type_info - print details about the type section of
 * of the ELF file header.
 * @type: the specified type of the elf file header.
 * @e_ident: an array that contains details about the
 * elf file header.
 */
void print_type_info(unsigned int type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		default:
			printf("<unknown: %x>\n", type);
	}
}

/**
 * print_entry_info - prints information about the
 * entry point of the ELF file header.
 * @entry: address of the ELF file entry point.
 * @e_ident: an array that contains information about the
 * ELF file header class.
 */
void print_entry_info(unsigned long int entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);
	else
		printf("%#lx\n", entry);
}

/**
 * close_file_desc - closes a file descriptor argument.
 * @file_desc: a file descriptor for the elf file..
 */
void close_file_desc(int file_desc)
{
	if (close(file_desc))
	{
		dprintf(2, "Error: Can't close fd %d\n", file_desc);
		exit(98);
	}
}

