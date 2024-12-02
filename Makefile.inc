APPL_COBJS +=

APPL_CXXOBJS +=	SetMotor.o\
                B_ColorSensor.o\
                Display.o\
                Botton.o\
                RunAction.o\
                LineTrace.o\
                Speaker.o\
                MotorControl.o\
                Distance.o\
                Scene.o\
                Section1.o\
                SecondSection.o\
                ThirdSection.o\
                BGMControl.o

SRCLANG := c++
COPTS += -std=c++11
INCLUDES += -I$(ETROBO_HRP3_WORKSPACE)/etroboc_common

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile
include $(EV3RT_SDK_LIB_DIR)/lib2/Makefile

endif
