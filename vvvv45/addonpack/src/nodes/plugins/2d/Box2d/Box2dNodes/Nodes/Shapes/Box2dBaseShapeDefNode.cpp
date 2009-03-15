#include "StdAfx.h"
#include "Box2dBaseShapeDefNode.h"

namespace VVVV 
{
	namespace Nodes 
	{
		Box2dBaseShapeDefNode::Box2dBaseShapeDefNode(void)
		{
		}

		void Box2dBaseShapeDefNode::SetPluginHost(IPluginHost^ Host)
		{
			this->FHost = Host;

			this->m_shapes = gcnew ShapeDefDataType();

			//Output
			this->OnPluginHostSet();

			//Generic shape information
			this->FHost->CreateValueInput("Density",1,ArrayUtils::Array1D(),TSliceMode::Dynamic,TPinVisibility::True,this->vInDensity);
			this->vInDensity->SetSubType(0,Double::MaxValue,0.01,1.0,false,false,false);

			this->FHost->CreateValueInput("Friction",1,ArrayUtils::Array1D(),TSliceMode::Dynamic,TPinVisibility::True,this->vInFriction);
			this->vInFriction->SetSubType(0,Double::MaxValue,0.01,0.3,false,false,false);

			this->FHost->CreateValueInput("Restitution",1,ArrayUtils::Array1D(),TSliceMode::Dynamic,TPinVisibility::True,this->vInRestitution);
			this->vInRestitution->SetSubType(0,Double::MaxValue,0.01,1.0,false,false,false);

			this->FHost->CreateNodeOutput("Output",TSliceMode::Dynamic,TPinVisibility::True,this->vOutShapes);
			this->vOutShapes->SetSubType(ArrayUtils::SingleGuidArray(ShapeDefDataType::GUID),ShapeDefDataType::FriendlyName);
			this->vOutShapes->SetInterface(this->m_shapes);


		}

		void Box2dBaseShapeDefNode::Configurate(IPluginConfig^ Input) {}

	}
}
