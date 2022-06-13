#include "Model.h"

Model::Model(const double trueCoordinateX, const double trueCoordinateY, const double baseL, const double maxAngleError, const double position)
    : m_baseL(baseL),
      m_defPoint(trueCoordinateX, trueCoordinateY),
      m_visor1(Visor(m_defPoint, position, maxAngleError)),
      m_visor2(Visor(m_defPoint, position + m_baseL, maxAngleError)),
      m_analyzer(Analyzer(m_visor1, m_visor2)),
      m_logManager(m_analyzer.GetDiagonal1(), m_analyzer.GetDiagonal2())
{

}

void Model::Iteration(double position)
{
    m_visor1.Recalculate(position);
    m_visor2.Recalculate(position + m_baseL);
    m_analyzer.Recalculate(m_visor1, m_visor2);
    m_logManager.Iteration(m_analyzer.GetDiagonal1(), m_analyzer.GetDiagonal2());
}

std::vector<std::vector<double>> Model::GetLogTable()
{
    return m_logManager.GetLogTable();
}
