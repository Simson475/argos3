/*
 * @file <argos3/plugins/robots/generic/simulator/radios_default_actuator.h>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#ifndef RADIOS_DEFAULT_ACTUATOR_H
#define RADIOS_DEFAULT_ACTUATOR_H

namespace argos {
   class CRadiosDefaultActuator;
}

#include <argos3/core/simulator/actuator.h>
#include <argos3/plugins/robots/generic/control_interface/ci_radios_actuator.h>
#include <argos3/plugins/simulator/entities/radio_equipped_entity.h>
#include <argos3/plugins/simulator/media/radio_medium.h>

namespace argos {

   class CRadiosDefaultActuator : public CSimulatedActuator,
                                  public CCI_RadiosActuator {

   public:

      CRadiosDefaultActuator();

      virtual ~CRadiosDefaultActuator() {}

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   private:

      CRadioEquippedEntity* m_pcRadioEquippedEntity;

      class CSendOperation : public CPositionalIndex<CRadioEntity>::COperation {
      public:

         CSendOperation(const CRadioEntity& c_radio,
                        const std::vector<CByteArray>& c_messages) :
            m_cRadio(c_radio),
            m_cMessages(c_messages) {}

         virtual bool operator()(CRadioEntity& c_radio);

      private:

         const CRadioEntity& m_cRadio;
         const std::vector<CByteArray>& m_cMessages;
      };
   };
}

#endif
