#ifndef CONSTS_HPP
#define CONSTS_HPP

namespace DifficultySpace
{
  constexpr const char *EASY = "easy";
  constexpr const char *MEDIUM = "medium";
  constexpr const char *HARD = "hard";
}

namespace StatusSpace
{
  constexpr const char *CORRECTS = "corrects";
  constexpr const char *INCORRECTS = "incorrects";
  constexpr const char *BLANKS = "blanks";
  constexpr const char *UNSEEN = "unseen";
}

namespace CommandSpace
{
  constexpr const char *CREATE_TEMPLATE = "create_template";
  constexpr const char *GENERATE_TEST = "generate_test";
  constexpr const char *AUTO_GENERATE = "auto_generate";
  constexpr const char *ATTEND = "attend";
  constexpr const char *REPORT = "report";
}

namespace ReportFlagSpace
{
  constexpr const char *ALL = "all";
  constexpr const char *TEST = "test";
  constexpr const char *TESTS = "tests";
  constexpr const char *SUBJECT = "subject";
}

#endif 
