#pragma once

#include <AForm.hpp>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		~RobotomyRequestForm();

	private:
		// making sure requests fail 50% of the time no matter the object
		static void updateFailed();
		static bool	hasFailed;

		RobotomyRequestForm& operator = (const RobotomyRequestForm &obj);
		void callback() const;
};