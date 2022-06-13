#include "Model.h"

Model::Model(const int trueCoordinateX, const int trueCoordinateY, const int baseL, const int maxAngleError, int position)
    : m_baseL(baseL),
      m_visor1(Visor(trueCoordinateX, trueCoordinateY, position, maxAngleError)),
      m_visor2(Visor(trueCoordinateX, trueCoordinateY, position + m_baseL, maxAngleError)),
      m_analyzer(Analyzer(m_visor1, m_visor2)),
      m_logManager(m_analyzer.GetDiagonal1(), m_analyzer.GetDiagonal2())
{

}

void Model::Iteration(int position)
{
    m_visor1.Recalculate(position);
    m_visor2.Recalculate(position + m_baseL);
    m_analyzer.Recalculate(m_visor1, m_visor2);
    m_logManager.Iteration(m_analyzer.GetDiagonal1(), m_analyzer.GetDiagonal2());
}

std::vector<std::vector<int>> Model::GetLogTable()
{
    return m_logManager.GetLogTable();
}
