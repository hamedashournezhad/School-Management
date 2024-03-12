#pragma once
#define DSV 0
#define aml 4
#define tml 5
#define mlt 50
#define mct 10
#define mls 500
#define mcls 10
using std::string;
static char exitor = 'Y';
static char backer = 'Y';
static int len_teacher, len_student;
static int course_len, backgroundcolor, textcolor;
string tf_name[mls], tl_name[mls], tp_number[mls], te_mail[mls], tl_city[mls], t_gender[mls], t_course[mcls][mls];
string sf_name[mls], sl_name[mls], sp_number[mls], se_mail[mls], sl_city[mls], s_gender[mls], s_course[mcls][mls];
// Base Class
class Configuration
{
protected:
	string administration_menus[aml] = { "Teacher Management","Student Management","Settings", "Exit"};
	string teacher_management[tml] = { "Add a Teacher","Remove a Teacher","Teacher Student\'s","Show All Teacher\'s", "Back"};
	string student_management[tml] = { "Add a Student","Remove a Student","Student Teacher\'s","Show All Student\'s", "Back"};
	long int auth = 0;
public:
	static auto clear() -> void;
	static auto fade_animate(int animate_timer) -> void;
	static auto set_university_title(string get_university_title);
};
inline void Configuration::clear()
{
	system("cls");
}
inline auto Configuration::fade_animate(int animate_timer) -> void
{
	Sleep(animate_timer);
}
inline auto Configuration::set_university_title(std::basic_string<char> get_university_title)
{
	SetConsoleTitleA(get_university_title.data());
}


class Controller : protected Configuration
{
	std::string reg_user, reg_pass, log_user, log_pass;
	char account_exist{};
public:
	Controller();
	auto register_user() -> void;
	auto login_user() -> void;
	auto admin_control_panel(const string& username, const string& password) -> void;
	auto admin_control_panel_menus() const -> void;
	static auto teacher_students() -> void;
	auto teacher_menus() const -> void;
	auto student_menus() const -> void;
	auto get_teacher() const -> void;
	auto remove_teacher() const -> void;
	auto get_student() const -> void;
	auto change_theme() const -> void;
	auto remover_student() const -> void;
};
inline void Controller::teacher_students()
{
	set_university_title("Show teacher students");
	for (int i = DSV; i < len_student; i++)
	{
		std::cout << i + 1 << ") student Fullname: " << sf_name[i] << " " << sl_name[i] << "\n";
	}
}

inline void Controller::get_student() const
{
	clear();
	set_university_title("Adding Student..");
	for (int i = 0; i < len_student; i++)
	{
		std::cout << "Enter " << i + 1 << " student firstname: ";
		std::cin >> sf_name[i];
		std::cout << "Enter " << i + 1 << " student lastname: ";
		std::cin >> sl_name[i];
		std::cout << "Enter " << i + 1 << " student phone number: ";
		std::cin >> sp_number[i];
		std::cout << "Enter " << i + 1 << " student e-mail: ";
		std::cin >> se_mail[i];
		std::cout << "Enter " << i + 1 << " student living location: ";
		std::cin >> sl_city[i];
		std::cout << "Enter " << i + 1 << " student gender (Male/Female): ";
		std::cin >> s_gender[i];
		std::cout << "How many course do you wanna have?";
		std::cin >> course_len;
		for (int b = DSV; b < course_len; b++)
		{
			std::cout << "Enter " << b + 1 << " student course name: ";
			std::cin >> s_course[b][i];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	student_menus();
}


inline auto Controller::get_teacher() const -> void
{
	clear();
	set_university_title("Adding.. Teacher");
	for (int i = 0; i < len_teacher; i++)
	{
		std::cout << "Enter " << i + 1 << " teacher firstname: ";
		std::cin >> tf_name[i];
		std::cout << "Enter " << i + 1 << " teacher lastname: ";
		std::cin >> tl_name[i];
		std::cout << "Enter " << i + 1 << " teacher phone number: ";
		std::cin >> tp_number[i];
		std::cout << "Enter " << i + 1 << " teacher e-mail: ";
		std::cin >> te_mail[i];
		std::cout << "Enter " << i + 1 << " teacher living location: ";
		std::cin >> tl_city[i];
		std::cout << "Enter " << i + 1 << " teacher gender (Male/Female): ";
		std::cin >> t_gender[i];
		std::cout << "How many course do you wanna have?";
		std::cin >> course_len;
		for (int c = DSV; c < course_len; c++)
		{
			std::cout << "Enter " << c + 1 << " teacher course name: ";
			std::cin >> t_course[c][i];
		}
		std::cout << "\n";
	}
	for (int i = DSV; i < len_teacher; i++)
	{
		std::cout << i + 1 << " teacher first name: " << tf_name[i] << "\n";
		std::cout << i + 1 << " teacher last name: " <<  tl_name[i] << "\n";
		std::cout << i + 1 << " teacher phone number: " << tp_number[i] << "\n";
		std::cout << i + 1 << " teacher e-mail: " << te_mail[i] << "\n";
		std::cout << i + 1 << " teacher living location: " << tl_city[i] << "\n";
		std::cout << i + 1 << " teacher gender (Male/Female): " << t_gender[i] << "\n";
		std::cout << "How many course do you wanna show?";
		std::cin >> course_len;
			std::cout << "\nCourse\'s:\n";
			for (int c = DSV; c < course_len; c++)
			{
				std::cout << tf_name[i] << " " << tl_name[i] << " course name : " << t_course[c][i] << "\n";
			}
			std::cout << "\n";
	}
	std::cout << "\n";
	teacher_menus();
}

inline auto Controller::remove_teacher() const -> void
{
	clear();
	if (tf_name[0].empty())
	{
		char remove_teach;
		std::cout << "\n\tNot Found Any Data! \n\nDo You Wanna Add a Teacher(Y/n): ";
		std::cin >> remove_teach;
		if (remove_teach == 'Y' || remove_teach == 'y')
		{
			std::cout << "\n";
			teacher_menus();
		}
		else if (remove_teach == 'N' || remove_teach == 'n')
		{
			std::cout << "\n";
			admin_control_panel_menus();
		}
		else
		{
			admin_control_panel_menus();
		}
	}
	else {
		set_university_title("Teacher Removing..");
		std::cout << "Teacher List\'s: \n";
		for (int i = DSV; i < len_teacher; i++)
		{
			std::cout << tf_name[i] << " " << tl_name[i] << "\n";
		}
		string rem_fname, rem_lname = {};
		char remc_name = {};
		std::cout << "Enter his/her firstname: ";
		std::cin >> rem_fname;
		std::cout << "Enter his/her lastname: ";
		std::cin >> rem_lname;
		for (int p = DSV; p < len_teacher; p++)
		{
			if (rem_fname == tf_name[p] && rem_lname == tl_name[p])
			{
				std::cout << "Do you want to remove " << rem_fname << " " << rem_lname << "(Y/n): ";
				std::cin >> remc_name;
				if (remc_name == 'Y' || remc_name == 'y')
				{
					tf_name[p] = "";
					tl_name[p] = "";
				}
				else if (remc_name == 'N' || remc_name == 'n')
				{
					clear();
					teacher_menus();
				}
			}
		}
	}
	teacher_menus();
}

inline Controller::Controller()
{
	len_teacher = 0;
	reg_user = reg_pass = log_user = log_pass = {};
	std::cout << "Do you have any account(Y/n): ";
	std::cin >> account_exist;
	if(account_exist =='Y' || account_exist == 'y')
	{
		login_user();
	}else if(account_exist == 'N' || account_exist == 'n')
	{
		register_user();
	}else
	{
		system("color 04");
		std::cout << "\nThis arguments isn\'t true!" << std::endl;
		fade_animate(800);
		exit(EXIT_SUCCESS);
	}
}
inline void Controller::admin_control_panel(const string& username, const string& password)
{
	if (username == "admin" && password == "admin123")
	{
		system("color 02");
		clear();
		std::cout << "Data Processing..";
		fade_animate(800);
		clear();
		system("color 07");
		set_university_title("Confirmation..");
		std::cout << "Authentication Code: 196452";
		std::cout << "\n\nInsert Authentication Code: ";
		std::cin >> auth;
		while (auth != 196452)
		{
			std::cout << "\nInsert Authentication Code: ";
			std::cin >> auth;
		}
		admin_control_panel_menus();
	}else
	{
		login_user();
	}
}
inline void Controller::admin_control_panel_menus() const
{
	clear();
	set_university_title("Control Panel Menus");
	std::cout << "Hi " << log_user << ", Welcome To Azad University Control Panel!\n\n";
	for (int i = DSV; i < aml; i++)
	{
		std::cout << i + 1 << "_ " << administration_menus[i] << "\n";
		fade_animate(450);
	}
	std::cout << "\nChoice a number between 1 ~ " << aml << ": ";
	int administration_menu_selection = 0;
	std::cin >> administration_menu_selection;
	if(administration_menu_selection>=1 && administration_menu_selection<=7)
	{
		switch (administration_menu_selection)
		{
		case 1:
			std::cout << "\n";
			teacher_menus();
			break;

		case 2:
			student_menus();
			break;

		case 3:
			change_theme();
			break;

		case 4:
			std::cout << "Are you sure for close the program(Y/n): ";
			std::cin >> exitor;
			if (exitor == 'Y' || exitor == 'y')
			{
				exit(EXIT_SUCCESS);
			}
			else if (exitor == 'N' || exitor == 'n')
			{
				admin_control_panel_menus();
			}
			else
			{
				std::cout << "\nThis arguments isn\'t true!" << std::endl;
				fade_animate(800);
				admin_control_panel_menus();
			}
			break;
		}
	}else
	{
		std::cout << "\nProgram Service\'s Disabled!\n";
		fade_animate(500);
		exit(EXIT_FAILURE);
	}
}
inline auto Controller::remover_student() const -> void
{
	clear();
	if (sf_name[0].empty())
	{
		char remove_stu;
		std::cout << "\n\tNot Found Any Data! \n\nDo You Wanna Add a Student(Y/n): ";
		std::cin >> remove_stu;
		if (remove_stu == 'Y' || remove_stu == 'y')
		{
			std::cout << "\n";
			student_menus();
		}
		else if (remove_stu == 'N' || remove_stu == 'n')
		{
			std::cout << "\n";
			admin_control_panel_menus();
		}
		else
		{
			admin_control_panel_menus();
		}
	}
	else {
		set_university_title("Student Removing..");
		std::cout << "Student List\'s: \n";
		for (int i = DSV; i < len_student; i++)
		{
			std::cout << sf_name[i] << " " << sl_name[i] << "\n";
		}
		string rem_fname, rem_lname = {};
		char remc_name = {};
		std::cout << "Enter his/her firstname: ";
		std::cin >> rem_fname;
		std::cout << "Enter his/her lastname: ";
		std::cin >> rem_lname;
		for (int p = DSV; p < len_student; p++)
		{
			if (rem_fname == sf_name[p] && rem_lname == sl_name[p])
			{
				std::cout << "Do you want to remove " << rem_fname << " " << rem_lname << "(Y/n): ";
				std::cin >> remc_name;
				if (remc_name == 'Y' || remc_name == 'y')
				{
					sf_name[p] = "";
					sl_name[p] = "";
				}
				else if (remc_name == 'N' || remc_name == 'n')
				{
					clear();
					student_menus();
				}
			}
		}
	}
	std::cout << "\n";
	student_menus();
}

inline void Controller::register_user()
{
	set_university_title("Registration Page");
	clear();
	std::cout << "Enter Username: ";
	std::cin >> reg_user;
	while (reg_user.length() <= 2) {
		std::cout << "\n\tYour username most be greater than 6 character!\n\n";
		std::cout << "Enter Username: ";
		std::cin >> reg_user;
	}
	std::cout << "Enter Password: ";
	std::cin >> reg_pass;
	while (reg_pass.length() <= 6) {
		std::cout << "\n\tYour Password most be greater than 6 character!\n\n";
		std::cout << "Enter Password: ";
		std::cin >> reg_pass;
	}
	log_user = reg_user;
	admin_control_panel_menus();
}
inline void Controller::login_user()
{
	set_university_title("Login Page");
	clear();
	std::cout << "Enter Username: ";
	std::cin >> log_user;
	while (log_user.length() <= 2) {
		std::cout << "\n\tYour username most be greater than 6 character!\n\n";
		std::cout << "Enter Username: ";
		std::cin >> log_user;
	}
	std::cout << "Enter Password: ";
	std::cin >> log_pass;
	while (log_pass.length() <= 6) {
		std::cout << "\n\tYour Password most be greater than 6 character!\n\n";
		std::cout << "Enter Password: ";
		std::cin >> log_pass;
	}
	admin_control_panel(log_user, log_pass);
}
inline void Controller::teacher_menus() const
{
	set_university_title("Teacher Menus");
	for (int i = DSV; i < tml; i++)
	{
		std::cout << i + 1 << "_ " << teacher_management[i] << "\n";
		fade_animate(450);
	}
	std::cout << "\nChoice a number between 1 ~ " << tml << ": ";
	int teacher_menu_selection = 0;
	std::cin >> teacher_menu_selection;
	if (teacher_menu_selection >= 1 && teacher_menu_selection <= tml)
	{
		switch (teacher_menu_selection)
		{
		case 1:
			std::cout << "How many teacher do you wanna set: ";
			std::cin >> len_teacher;
			get_teacher();
			break;

		case 2:
			remove_teacher();
			break;

		case 3:
			if (sf_name[0].empty())
			{
				char add_student;
				std::cout << "\n\tNot Found Any Data! \n\nDo You Wanna Add a Student(Y/n): ";
				std::cin >> add_student;
				if (add_student == 'Y' || add_student == 'y')
				{
					std::cout << "\n";
					student_menus(); 
				}
				else if (add_student == 'N' || add_student == 'n')
				{
					std::cout << "\n";
					teacher_menus();
				}
				else
				{
					admin_control_panel_menus();
				}
			}
			else {
				std::cout << "\n";
				teacher_students();
			}
			break;

		case 4:
			if (tf_name[0].empty())
			{
				char add_teach;
				std::cout << "\n\tNot Found Any Data! \n\nDo You Wanna Add a Teacher(Y/n): ";
				std::cin >> add_teach;
				if(add_teach=='Y' || add_teach=='y')
				{
					std::cout << "\n";
					teacher_menus();
				}else if(add_teach=='N' || add_teach=='n')
				{
					std::cout << "\n";
					teacher_menus();
				}else
				{
					admin_control_panel_menus();
				}

			}else {
				std::cout << "\n";
				for (int r = DSV; r < len_teacher; r++)
				{
					std::cout << "Teacher (" << r + 1 << "): " << tf_name[r] << " " << tl_name[r] << "\n";
				}
				std::cout << "\n";
				teacher_menus();
			}
			break;

		case 5:
			std::cout << "Do You Wanna Go Back(Y/n): ";
			std::cin >> backer;
			if (backer == 'Y' || backer == 'y')
			{
				admin_control_panel_menus();
			}
			else if (backer == 'N' || backer == 'n')
			{
				std::cout << "\n";
				teacher_menus();
			}
			else
			{
				std::cout << "\nThis arguments isn\'t true!" << std::endl;
				fade_animate(800);
				teacher_menus();
				break;
			}
		}
	}
	else
	{
		std::cout << "\nProgram Service\'s Disabled!\n";
		fade_animate(500);
		exit(EXIT_FAILURE);
	}
}

inline void Controller::student_menus() const
{
	clear();
	set_university_title("Student Menus");
	for (int i = DSV; i < tml; i++)
	{
		std::cout << i + 1 << "_ " << student_management[i] << "\n";
		fade_animate(450);
	}
	std::cout << "\nChoice a number between 1 ~ " << tml << ": ";
	int student_menu_selection = 0;
	std::cin >> student_menu_selection;
	if (student_menu_selection >= 1 && student_menu_selection <= 5)
	{
		switch (student_menu_selection)
		{
		case 1:
			std::cout << "How many student do you wanna set: ";
			std::cin >> len_student;
			get_student();
			break;

		case 2:
			remover_student();
			break;

		case 3:
			if (sf_name[0].empty())
			{
				char add_stu;
				std::cout << "\n\tNot Found Any Data! \n\nDo You Wanna Add a Teacher(Y/n): ";
				std::cin >> add_stu;
				if (add_stu == 'Y' || add_stu == 'y')
				{
					std::cout << "\n";
					student_menus();
				}
				else if (add_stu == 'N' || add_stu == 'n')
				{
					std::cout << "\n";
					student_menus();
				}
				else
				{
					admin_control_panel_menus();
				}
			}
			else {
				std::cout << "\n";
				student_menus();
			}
			break;

		case 4:
			if (sf_name[0].empty())
			{
				char add_stu;
				std::cout << "\n\tNot Found Any Data! \n\nDo You Wanna Add a Student(Y/n): ";
				std::cin >> add_stu;
				if (add_stu == 'Y' || add_stu == 'y')
				{
					std::cout << "\n";
					student_menus();
				}
				else if (add_stu == 'N' || add_stu == 'n')
				{
					std::cout << "\n";
					student_menus();
				}
				else
				{
					admin_control_panel_menus();
				}

			}
			else {
				std::cout << "\n";
				for (int r = DSV; r < len_student; r++)
				{
					std::cout << "Student (" << r + 1 << "): " << sf_name[r] << " " << sl_name[r] << "\n";
				}
				std::cout << "\n";
				student_menus();
			}
			break;

		case 5:
			char backer = 'Y';
			std::cout << "Do You Wanna Go Back(Y/n): ";
			std::cin >> backer;
			if (backer == 'Y' || backer == 'y')
			{
				admin_control_panel_menus();
			}
			else if (backer == 'N' || backer == 'n')
			{
				student_menus();
			}
			else
			{
				std::cout << "\nThis arguments isn\'t true!" << std::endl;
				fade_animate(800);
				student_menus();
			}
			break;
		}
	}
	else
	{
		std::cout << "\nProgram Service\'s Disabled!\n";
		fade_animate(500);
		exit(EXIT_FAILURE);
	}
}

inline auto Controller::change_theme() const -> void
{
	std::cout << "Color Palette:\n0 = Black       1 = Blue\n2 = Green       3 = Aqua\n4 = Red        	5 = Purple\n6 = Yellow      7 = White\n\n";
	std::cout << "Enter a number for set background color: ";
	std::cin >> backgroundcolor;
	std::cout << "Enter a number for set text color ";
	std::cin >> textcolor;
	
	if (backgroundcolor == 0 && textcolor == 1)
	{
		system("color 01");
	}
	else if (backgroundcolor == 0 && textcolor == 2)
	{
		system("color 02");
	}
	else if (backgroundcolor == 0 && textcolor == 3)
	{
		system("color 03");
	}
	else if (backgroundcolor == 0 && textcolor == 4)
	{
		system("color 04");
	}
	else if (backgroundcolor == 0 && textcolor == 5)
	{
		system("color 05");
	}
	else if (backgroundcolor == 0 && textcolor == 6)
	{
		system("color 06");
	}
	else if (backgroundcolor == 0 && textcolor == 7)
	{
		system("color 07");
	}
	else if (backgroundcolor == 1 && textcolor == 0)
	{
		system("color 10");
	}
	else if (backgroundcolor == 1 && textcolor == 1)
	{
		std::cout << "You can\'t set a color for both!\n\nEnter a number for set text color: ";
		std::cin >> textcolor;
		while (!(int)textcolor)
		{
			std::cin >> textcolor;
		}
	}
	else if (backgroundcolor == 1 && textcolor == 2)
	{
		system("color 12");
	}
	else if (backgroundcolor == 1 && textcolor == 3)
	{
		system("color 13");
	}
	else if (backgroundcolor == 1 && textcolor == 4)
	{
		system("color 14");
	}
	else if (backgroundcolor == 1 && textcolor == 5)
	{
		system("color 15");
	}
	else if (backgroundcolor == 1 && textcolor == 6)
	{
		system("color 16");
	}
	else if (backgroundcolor == 1 && textcolor == 7)
	{
		system("color 17");
	}
	else if (backgroundcolor == 2 && textcolor == 0)
	{
		system("color 20");
	}
	else if (backgroundcolor == 2 && textcolor == 1)
	{
		system("color 21");
	}
	else if (backgroundcolor == 2 && textcolor == 2)
	{
		std::cout << "You can\'t set a color for both!\n\nEnter a number for set text color: ";
		std::cin >> textcolor;
		while (!(int)textcolor)
		{
			std::cin >> textcolor;
		}
	}
	else if (backgroundcolor == 2 && textcolor == 3)
	{
		system("color 23");
	}
	else if (backgroundcolor == 2 && textcolor == 4)
	{
		system("color 24");
	}
	else if (backgroundcolor == 2 && textcolor == 5)
	{
		system("color 25");
	}
	else if (backgroundcolor == 2 && textcolor == 6)
	{
		system("color 26");
	}
	else if (backgroundcolor == 2 && textcolor == 7)
	{
		system("color 27");
	}
	else if (backgroundcolor == 3 && textcolor == 0)
	{
		system("color 30");
	}
	else if (backgroundcolor == 3 && textcolor == 1)
	{
		system("color 31");
	}
	else if (backgroundcolor == 3 && textcolor == 2)
	{
		system("color 32");
	}
	else if (backgroundcolor == 3 && textcolor == 3)
	{
	std::cout << "You can\'t set a color for both!\n\nEnter a number for set text color: ";
	std::cin >> textcolor;
	while (!(int)textcolor)
	{
		std::cin >> textcolor;
	}
	}
	else if (backgroundcolor == 3 && textcolor == 4)
	{
		system("color 34");
	}
	else if (backgroundcolor == 3 && textcolor == 5)
	{
		system("color 35");
	}
	else if (backgroundcolor == 3 && textcolor == 6)
	{
		system("color 36");
	}
	else if (backgroundcolor == 3 && textcolor == 7)
	{
		system("color 37");
	}
	else if (backgroundcolor == 4 && textcolor == 0)
	{
		system("color 40");
	}
	else if (backgroundcolor == 4 && textcolor == 1)
	{
		system("color 41");
	}
	else if (backgroundcolor == 4 && textcolor == 2)
	{
		system("color 42");
	}
	else if (backgroundcolor == 4 && textcolor == 3)
	{
		system("color 43");
	}
	else if (backgroundcolor == 4 && textcolor == 4)
	{
	std::cout << "You can\'t set a color for both!\n\nEnter a number for set text color: ";
	std::cin >> textcolor;
	while (!(int)textcolor)
	{
		std::cin >> textcolor;
	}
	}
	else if (backgroundcolor == 4 && textcolor == 5)
	{
		system("color 45");
	}
	else if (backgroundcolor == 4 && textcolor == 6)
	{
		system("color 46");
	}
	else if (backgroundcolor == 4 && textcolor == 7)
	{
		system("color 47");
	}
	else if (backgroundcolor == 5 && textcolor == 0)
	{
		system("color 50");
	}
	else if (backgroundcolor == 5 && textcolor == 1)
	{
		system("color 51");
	}
	else if (backgroundcolor == 5 && textcolor == 2)
	{
		system("color 52");
	}
	else if (backgroundcolor == 5 && textcolor == 3)
	{
		system("color 53");
	}
	else if (backgroundcolor == 5 && textcolor == 4)
	{
		system("color 54");
	}
	else if (backgroundcolor == 5 && textcolor == 5)
	{
	std::cout << "You can\'t set a color for both!\n\nEnter a number for set text color: ";
	std::cin >> textcolor;
	while (!(int)textcolor)
	{
		std::cin >> textcolor;
	}
	}
	else if (backgroundcolor == 5 && textcolor == 6)
	{
		system("color 56");
	}
	else if (backgroundcolor == 5 && textcolor == 7)
	{
		system("color 57");
	}
	else if (backgroundcolor == 6 && textcolor == 0)
	{
		system("color 60");
	}
	else if (backgroundcolor == 6 && textcolor == 1)
	{
		system("color 61");
	}
	else if (backgroundcolor == 6 && textcolor == 2)
	{
		system("color 62");
	}
	else if (backgroundcolor == 6 && textcolor == 3)
	{
		system("color 63");
	}
	else if (backgroundcolor == 6 && textcolor == 4)
	{
		system("color 64");
	}
	else if (backgroundcolor == 6 && textcolor == 5)
	{
		system("color 65");
	}
	else if (backgroundcolor == 6 && textcolor == 6)
	{
	std::cout << "You can\'t set a color for both!\n\nEnter a number for set text color: ";
	std::cin >> textcolor;
	while (!(int)textcolor)
	{
		std::cin >> textcolor;
	}
	}
	else if (backgroundcolor == 6 && textcolor == 7)
	{
	system("color 67");
	}
	else if (backgroundcolor == 7 && textcolor == 0)
	{
	system("color 70");
	}
	else if (backgroundcolor == 7 && textcolor == 1)
	{
	system("color 71");
	}
	else if (backgroundcolor == 7 && textcolor == 2)
	{
	system("color 72");
	}
	else if (backgroundcolor == 7 && textcolor == 3)
	{
	system("color 73");
	}
	else if (backgroundcolor == 7 && textcolor == 4)
	{
	system("color 74");
	}
	else if (backgroundcolor == 7 && textcolor == 5)
	{
	system("color 75");
	}
	else if (backgroundcolor == 7 && textcolor == 6)
	{
	system("color 76");
	}
	else if (backgroundcolor == 7 && textcolor == 7)
	{
	std::cout << "You can\'t set a color for both!\n\nEnter a number for set text color: ";
	std::cin >> textcolor;
	while (!(int)textcolor)
	{
		std::cin >> textcolor;
	}
	}
	admin_control_panel_menus();
}
