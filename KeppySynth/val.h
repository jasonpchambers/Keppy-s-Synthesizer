// Keppy's Synthesizer Values

// Outputs
#ifndef __VAL_H
#define __VAL_H

SHA256 sha256;
#define STRINGIFY(...) #__VA_ARGS__
#define STR(...) STRINGIFY(__VA_ARGS__)

extern "C" __declspec(dllexport) void CompilerID(char * out, int length)
{
	// Replace this with your signature. You can find a base called signature.bas, in the main directory
	// of the source code.
	// The string NEEDS to be 256 chars long. You can use numbers and lowercase/uppercase letters.
	const char* a =
	{
#include "signature.kep"
	};
	std::string shacode = sha256(a);
	strcpy_s(out, length, shacode.c_str());
}

extern "C" __declspec(dllexport) LPCSTR KepSays()
{
	LPCSTR KepSaidWhat[8] =
	{
		"VirtualMIDISynth shall copy me no more.",
		"I am quite a charming guy.",
		"I don't like salty people, being salty myself."
		"H3H3 is an awesome YouTuber.",
		"H3Y B0SS",
		"Gingeas is the supreme master.",
		"Welcome to Windows 95.",
		"Sexy.",
	};

	int randomwhat = rand() % 8;

	return KepSaidWhat[randomwhat];
}

#endif 

// Mandatory values
static sound_out * sound_driver = NULL;
static HINSTANCE hinst = NULL;			//main DLL handle

static HINSTANCE bass = 0;				// bass handle
static HINSTANCE bass_vst = 0;			// bass_vst handle
static HINSTANCE bassenc = 0;			// bassenc handle
static HINSTANCE bassmidi = 0;			// bassmidi handle

// Potato
static float currentcpuusage0;
static int currentvoicesint0;
static int isoverrideenabled = 0;

// Main values
static HANDLE hConsole;					// Debug console
static float *sndbf;
static int allhotkeys = 0;				// Enable/Disable all the hotkeys
static int allnotesignore = 0;			// Ignore all MIDI events
static int alreadyshown = 0;			// Check if the info about the drivers have been already shown.
static int autopanic = 1;				// Autopanic switch
static int bassoutputfinal = 0;			// DO NOT TOUCH
static int debugmode = 0;				// Debug console
static int defaultmidiout = 0;			// Set as default MIDI out device for 8.x or newer
static int defaultoutput = 0;			// Default audio output (DSound)
static int driverprio = 0;				// Process priority
static int midiinenabled = 0;			// MIDI Input
static int defaultmidiindev = 0;		// MIDI Input device
static int defaultsflist = 1;			// Default soundfont list
static int encmode = 0;					// Encoder mode
static int floatrendering = 1;			// Floating point audio
static int frames = 0;					// Default
static int frequency = 0;				// Audio frequency
static int frequencynew = 0;			// Audio frequency
static int ignorenotes1 = 0;			// Ignores notes with velocity of 1
static int pitchshift = 127;			// Pitch shift
static int fadeoutdisable = 0;			// Disable fade-out
static int maxcpu = 0;					// CPU usage INT
static int midivoices = 0;				// Max voices INT
static int midivolumeoverride = 0;		// MIDI track volume override
static int newevbuffvalue = 64;			// DO NOT TOUCH
static int newsndbfvalue;				// DO NOT TOUCH
static int noaudiodevices = 0;			// No audio devices flag
static int nofloat = 1;					// Enable or disable the float engine
static int nofx = 0;					// Enable or disable FXs
static int noteoff1 = 0;				// Note cut INT
static int oldbuffermode = 0;			// For old-ass PCs
static int monorendering = 0;			// Mono rendering (Instead of stereo by default)
static int preload = 0;					// Soundfont preloading
static int rco = 0;						// Reduce CPU overhead
static int shortname = 0;				// Use short name or nah
static int sinc = 0;					// Sinc
static int sysexignore = 0;				// Ignore SysEx events
static int sysresetignore = 0;			// Ignore sysex messages
static int vms2emu = 0;					// VirtualMIDISynth 2.x buffer emulation
static int vmsemu = 0;					// VirtualMIDISynth buffer emulation
static int volume = 0;					// Volume limit
static int volumehotkeys = 1;			// Enable/Disable volume hotkeys
static int volumemon = 1;				// Volume monitoring
static int xaudiodisabled = 0;			// Override the default engine

// Priority values
static int prioval[7] =
{
	15,
	15,
	2,
	1,
	0,
	-1,
	-2
};

static int callprioval[7] =
{
	0x00000100,
	0x00000100,
	0x00000080,
	0x00008000,
	0x0000020,
	0x00004000,
	0x0000040
};

// BASS_VST load status
static int isbassvstloaded = 0;

// Channels volume
static LPCWSTR cnames[16] =
{
	L"ch1", L"ch2", L"ch3", L"ch4", L"ch5", L"ch6", L"ch7", L"ch8",
	L"ch9", L"ch10", L"ch11", L"ch2", L"ch13", L"ch14", L"ch15", L"ch16"
};

// Synth names
static char SynthName[MAXPNAMELEN];
static char SynthNameW[MAXPNAMELEN];
static int selectedname = 0;			// Default name
const int defaultarraysize = 23;		// Default array size

static LPCSTR SynthNames[defaultarraysize] =
{
	"Keppy's Synthesizer\0",
	"AWE64 MIDI Synth\0",
	"BASSMIDI Driver\0",
	"BASSMIDI Driver (Port A)\0",
	"BASSMIDI Driver (Port B)\0",
	"CoolSoft VirtualMIDISynth\0",
	"Creative OPL3 FM\0",
	"Microsoft GS Wavetable Synth\0",
	"Microsoft Synthesizer\0",
	"NVIDIA� Wavetable Synthesizer\0",
	"SB AWE32 MIDI Synth\0",
	"SB Live! Synth A\0",
	"SB Live! Synth B\0",
	"SoundMAX Wavetable Synth\0",
	"Timidity++ Driver\0",
	"USB Audio Device",
	"VirtualMIDISynth #1\0",
	"VirtualMIDISynth #2\0",
	"VirtualMIDISynth #3\0",
	"VirtualMIDISynth #4\0",
	"Windows OPL3 Synth\0",
	"YMF262 Synth Emulator\0",
	"Yamaha S-YXG50 SoftSynthesizer\0",
};

static LPCWSTR SynthNamesW[defaultarraysize] =
{
	L"Keppy's Synthesizer\0",
	L"AWE64 MIDI Synth\0",
	L"BASSMIDI Driver\0",
	L"BASSMIDI Driver (Port A)\0",
	L"BASSMIDI Driver (Port B)\0",
	L"CoolSoft VirtualMIDISynth\0",
	L"Creative OPL3 FM\0",
	L"Microsoft GS Wavetable Synth\0",
	L"Microsoft Synthesizer\0",
	L"NVIDIA� Wavetable Synthesizer\0",
	L"SB AWE32 MIDI Synth\0",
	L"SB Live! Synth A\0",
	L"SB Live! Synth B\0",
	L"SoundMAX Wavetable Synth\0",
	L"Timidity++ Driver\0",
	L"USB Audio Device",
	L"VirtualMIDISynth #1\0",
	L"VirtualMIDISynth #2\0",
	L"VirtualMIDISynth #3\0",
	L"VirtualMIDISynth #4\0",
	L"Windows OPL3 Synth\0",
	L"YMF262 Synth Emulator\0",
	L"Yamaha S-YXG50 SoftSynthesizer\0",
};

static int SynthNamesTypes[defaultarraysize] =
{
	MOD_MIDIPORT,						// Keppy's Synthesizer
	MOD_MIDIPORT,						// AWE64 MIDI Synth
	MOD_MIDIPORT,						// BASSMIDI Driver
	MOD_MIDIPORT,						// BASSMIDI Driver (Port A)
	MOD_MIDIPORT,						// BASSMIDI Driver (Port B)
	MOD_SWSYNTH,						// CoolSoft VirtualMIDISynth
	MOD_FMSYNTH,						// Creative OPL3 FM
	MOD_SWSYNTH,						// Microsoft GS Wavetable Synth
	MOD_WAVETABLE,						// Microsoft Synthesizer
	MOD_WAVETABLE,						// NVIDIA� Wavetable Synthesizer
	MOD_WAVETABLE,						// SB AWE32 MIDI Synth
	MOD_WAVETABLE,						// SB Live! Synth A
	MOD_WAVETABLE,						// SB Live! Synth B
	MOD_WAVETABLE,						// SoundMAX Wavetable Synth
	MOD_MIDIPORT,						// Timidity++ Driver
	MOD_MIDIPORT,						// USB Audio Device
	MOD_SWSYNTH,						// VirtualMIDISynth #1
	MOD_SWSYNTH,						// VirtualMIDISynth #2
	MOD_SWSYNTH,						// VirtualMIDISynth #3
	MOD_SWSYNTH,						// VirtualMIDISynth #4
	MOD_FMSYNTH,						// Windows OPL3 Synth
	MOD_FMSYNTH,						// YMF262 Synth Emulator
	MOD_WAVETABLE,						// Yamaha S-YXG50 SoftSynthesizer
};

// Channels
static int cvalues[16] =
{
	16383, 16383, 16383, 16383, 16383, 16383, 16383, 16383,
	16383, 16383, 16383, 16383, 16383, 16383, 16383, 16383
};

static int tcvalues[16] =
{
	16383, 16383, 16383, 16383, 16383, 16383, 16383, 16383,
	16383, 16383, 16383, 16383, 16383, 16383, 16383, 16383
};

// Watchdog stuff
static LPCWSTR rnames[16] =
{
	L"rel1", L"rel2", L"rel3", L"rel4", L"rel5", L"rel6", L"rel7", L"rel8",
	L"rel9", L"rel10", L"rel11", L"rel2", L"rel13", L"rel14", L"rel15", L"rel16"
};

static int rvalues[16] =
{
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};

// Other
static int buffull = 0;
static int extra8lists = 0;
static int lovel = 1;
static int hivel = 1;

// Buffer system
static BYTE gs_part_to_ch[16];
static BYTE drum_channels[16];
static const char sysex_gm_reset[] = { 0xF0, 0x7E, 0x7F, 0x09, 0x01, 0xF7 };
static const char sysex_gs_reset[] = { 0xF0, 0x41, 0x10, 0x42, 0x12, 0x40, 0x00, 0x7F, 0x00, 0x41, 0xF7 };
static const char sysex_xg_reset[] = { 0xF0, 0x43, 0x10, 0x4C, 0x00, 0x00, 0x7E, 0x00, 0xF7 };

// Soundfont lists
static TCHAR userprofile[MAX_PATH];

// -----------------------------------------------------------------------

static TCHAR sfdir1[MAX_PATH];
static TCHAR sfdir2[MAX_PATH];
static TCHAR sfdir3[MAX_PATH];
static TCHAR sfdir4[MAX_PATH];
static TCHAR sfdir5[MAX_PATH];
static TCHAR sfdir6[MAX_PATH];
static TCHAR sfdir7[MAX_PATH];
static TCHAR sfdir8[MAX_PATH];
static TCHAR sfdir9[MAX_PATH];
static TCHAR sfdir10[MAX_PATH];
static TCHAR sfdir11[MAX_PATH];
static TCHAR sfdir12[MAX_PATH];
static TCHAR sfdir13[MAX_PATH];
static TCHAR sfdir14[MAX_PATH];
static TCHAR sfdir15[MAX_PATH];
static TCHAR sfdir16[MAX_PATH];

static TCHAR * sflistloadme[16] =
{
	sfdir1, sfdir2, sfdir3, sfdir4, sfdir5, sfdir6, sfdir7, sfdir8,
	sfdir9, sfdir10, sfdir11, sfdir12, sfdir13, sfdir14, sfdir15, sfdir16
};

static TCHAR * sfdirs[16] =
{
	L"\\Keppy's Synthesizer\\lists\\keppymidi.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidib.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidic.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidid.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidie.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidif.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidig.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidih.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidii.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidij.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidik.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidil.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidim.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidin.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidio.sflist",
	L"\\Keppy's Synthesizer\\lists\\keppymidip.sflist"
};

// -----------------------------------------------------------------------

static TCHAR listsloadme1[MAX_PATH];
static TCHAR listsloadme2[MAX_PATH];
static TCHAR listsloadme3[MAX_PATH];
static TCHAR listsloadme4[MAX_PATH];
static TCHAR listsloadme5[MAX_PATH];
static TCHAR listsloadme6[MAX_PATH];
static TCHAR listsloadme7[MAX_PATH];
static TCHAR listsloadme8[MAX_PATH];
static TCHAR listsloadme9[MAX_PATH];
static TCHAR listsloadme10[MAX_PATH];
static TCHAR listsloadme11[MAX_PATH];
static TCHAR listsloadme12[MAX_PATH];
static TCHAR listsloadme13[MAX_PATH];
static TCHAR listsloadme14[MAX_PATH];
static TCHAR listsloadme15[MAX_PATH];
static TCHAR listsloadme16[MAX_PATH];

static TCHAR * listsloadme[16] =
{
	listsloadme1, listsloadme2, listsloadme3, listsloadme4, listsloadme5, listsloadme6, listsloadme7, listsloadme8,
	listsloadme9, listsloadme10, listsloadme11, listsloadme12, listsloadme13, listsloadme14, listsloadme15, listsloadme16
};

static TCHAR * listsanalyze[16] =
{
	L"\\Keppy's Synthesizer\\applists\\keppymidi.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidib.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidic.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidid.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidie.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidif.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidig.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidih.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidii.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidij.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidik.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidil.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidim.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidin.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidio.applist",
	L"\\Keppy's Synthesizer\\applists\\keppymidip.applist"
};

// -----------------------------------------------------------------------

std::vector<HSOUNDFONT> _soundFonts[16];
std::vector<BASS_MIDI_FONTEX> presetList[16];

// -----------------------------------------------------------------------

static int pitchshiftchan[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static LPCWSTR pitchshiftname[16] =
{
	L"ch1pshift", L"ch2pshift", L"ch3pshift", L"ch4pshift", L"ch5pshift",
	L"ch6pshift", L"ch7pshift", L"ch8pshift", L"ch9pshift", L"ch10pshift",
	L"ch11pshift", L"ch12pshift", L"ch13pshift", L"ch14pshift", L"ch15pshift", 
	L"ch16pshift"
};