#include <gtest/gtest.h>
#include "MockMoveableObject.h"
#include "MockStaticObject.h"
#include "MockRotableObject.h"
#include "MoveCommand.h"
#include "RotateCommand.h"
#include "CheckFuelCommand.h"
#include "BurnFuelCommand.h"
#include "MacroCommand.h"

// Проверка выброса исключения, когда недостаточно топлива
TEST(CheckFuelCommand, CheckFuel)
{
	ASSERT_THROW(
		{
			int fuel = 0;
			CheckFuelCommand checkFuel(&fuel);
			checkFuel.Execute();
		},
		CommandException);
}
// проверка уменьшения топлива
TEST(BurnFuelCommand, BurnFuel)
{
	int fuel = 100;
	BurnFuelCommand burnFuel(&fuel);
	burnFuel.Execute();

	EXPECT_EQ(fuel, 99);
}
// проверка выброса исключения CommandException 
// при прямолинейном движении
TEST(MacroCommand, MacroCommand)
{
	ASSERT_THROW(
		{
			int fuel = 2;

			CheckFuelCommand checkFuel(&fuel);
			BurnFuelCommand burnFuel(&fuel);
			MockMoveableObject obj(Vector(0, 0), Vector(1, 0));
			MoveCommand moveCommand(&obj);

			std::vector<ICommand*> cmds;
			cmds.reserve(fuel * 3);
			for (int i = 0; i <= fuel; ++i)
			{
				cmds.push_back(&checkFuel);
				cmds.push_back(&moveCommand);
				cmds.push_back(&burnFuel);
			}

			MacroCommand commands(cmds);
			commands.Execute();
		},
		CommandException);
}
