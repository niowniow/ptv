# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Debug
  OUTDIR := ../../../bin

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "PTV_ARMV7" -D "JUCER_LINUX_MAKE_B0236055=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../../sdk/VST3SDK -I ../../../JuceLibraryCode -I ../../../sdk/JUCE/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 

  TARGET := PushTheVibe_armv7
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := ../../../bin

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "NDEBUG=1" -D "PTV_ARMV7" -D "JUCER_LINUX_MAKE_B0236055=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../../sdk/VST3SDK -I ../../../JuceLibraryCode -I ../../../sdk/JUCE/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -O3
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -fvisibility=hidden -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 

  TARGET := PushTheVibe_armv7
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
  $(OBJDIR)/InternalFilters_beb54bdf.o \
  $(OBJDIR)/Main_90ebc5c2.o \
  $(OBJDIR)/oscReceiver_defbb98f.o \
  $(OBJDIR)/ptvAudioCallback_2e1fd652.o \
  $(OBJDIR)/PushTheVibe_c99c51ae.o \
  $(OBJDIR)/IpEndpointName_b8828090.o \
  $(OBJDIR)/NetworkingUtils_253207fe.o \
  $(OBJDIR)/UdpSocket_dd986df5.o \
  $(OBJDIR)/OscOutboundPacketStream_35cdaa8.o \
  $(OBJDIR)/OscPrintReceivedElements_7156ff9f.o \
  $(OBJDIR)/OscReceivedElements_384654e8.o \
  $(OBJDIR)/OscTypes_6275ad53.o \
  $(OBJDIR)/juce_audio_basics_67908000.o \
  $(OBJDIR)/juce_audio_devices_4b1bd4be.o \
  $(OBJDIR)/juce_audio_formats_799d1e5e.o \
  $(OBJDIR)/juce_audio_processors_180559b8.o \
  $(OBJDIR)/juce_audio_utils_e5407b7e.o \
  $(OBJDIR)/juce_core_f49908e2.o \
  $(OBJDIR)/juce_data_structures_850d471e.o \
  $(OBJDIR)/juce_events_9ad83456.o \
  $(OBJDIR)/juce_graphics_1ffef8ba.o \
  $(OBJDIR)/juce_gui_basics_9f837336.o \
  $(OBJDIR)/juce_gui_extra_3f74fa3e.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(RESOURCES)
	@echo Linking PushTheVibe
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning PushTheVibe
	@$(CLEANCMD)

strip:
	@echo Stripping PushTheVibe
	-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/InternalFilters_beb54bdf.o: ../../Source/InternalFilters.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling InternalFilters.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Main_90ebc5c2.o: ../../Source/Main.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Main.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/oscReceiver_defbb98f.o: ../../Source/oscReceiver.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling oscReceiver.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ptvAudioCallback_2e1fd652.o: ../../Source/ptvAudioCallback.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ptvAudioCallback.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PushTheVibe_c99c51ae.o: ../../Source/PushTheVibe.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PushTheVibe.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/IpEndpointName_b8828090.o: ../../Source/ip/IpEndpointName.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling IpEndpointName.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/NetworkingUtils_253207fe.o: ../../Source/ip/NetworkingUtils.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling NetworkingUtils.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/UdpSocket_dd986df5.o: ../../Source/ip/UdpSocket.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling UdpSocket.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OscOutboundPacketStream_35cdaa8.o: ../../Source/osc/OscOutboundPacketStream.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscOutboundPacketStream.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OscPrintReceivedElements_7156ff9f.o: ../../Source/osc/OscPrintReceivedElements.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscPrintReceivedElements.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OscReceivedElements_384654e8.o: ../../Source/osc/OscReceivedElements.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscReceivedElements.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OscTypes_6275ad53.o: ../../Source/osc/OscTypes.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscTypes.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_67908000.o: ../../../sdk/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_4b1bd4be.o: ../../../sdk/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_799d1e5e.o: ../../../sdk/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_180559b8.o: ../../../sdk/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_utils_e5407b7e.o: ../../../sdk/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_utils.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_f49908e2.o: ../../../sdk/JUCE/modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_850d471e.o: ../../../sdk/JUCE/modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_9ad83456.o: ../../../sdk/JUCE/modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_1ffef8ba.o: ../../../sdk/JUCE/modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_9f837336.o: ../../../sdk/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_3f74fa3e.o: ../../../sdk/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
