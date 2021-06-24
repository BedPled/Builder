#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

enum MOTHERBOARD {
    mMSI,
    mASUS,
    mGIGABYTE,
    mASROCK
};

enum CPU {
    cAMD_RYZEN_3,
    cAMD_RYZEN_5,
    cAMD_RYZEN_7,
    cINTEL_I3,
    cINTEL_I5,
    cINTEL_I7,
};

enum VIDEOCARD {
    vAMD_RADEON_550,
    vNVIDIA_GTX_1080,
    vNVIDIA_RTX_3080,
    vAMD_RADEON_RX6900
};

class PC {
    MOTHERBOARD motherboard;
    CPU cpu;
    VIDEOCARD videocard;
    friend class intelGamePCBilder;
    friend class simplePCBilder;

public:
    string toString() {
        string s = "motherboard:";

        switch (motherboard) {
            case MOTHERBOARD::mMSI: s += " MSI"; break;
            case MOTHERBOARD::mASUS: s += " ASUS"; break;
            case MOTHERBOARD::mGIGABYTE: s += " GIGABYTE"; break;
            case MOTHERBOARD::mASROCK: s += " ASROCK"; break;
        }

        s+=", ";

        switch (cpu) {
            case CPU::cAMD_RYZEN_3: s += " AMD RYZEN 3"; break;
            case CPU::cAMD_RYZEN_5: s += " AMD RYZEN 5"; break;
            case CPU::cAMD_RYZEN_7: s += " AMD RYZEN 7"; break;
            case CPU::cINTEL_I3: s += " INTEL I3"; break;
            case CPU::cINTEL_I5: s += " INTEL I5"; break;
            case CPU::cINTEL_I7: s += " INTEL I7"; break;
        }

        switch (videocard) {
            case VIDEOCARD::vAMD_RADEON_550: s += " AMD RADEON 550"; break;
            case VIDEOCARD::vNVIDIA_GTX_1080: s += " NVIDIA GTX 1080"; break;
            case VIDEOCARD::vNVIDIA_RTX_3080: s += " NVIDIA GTX 3080"; break;
            case VIDEOCARD::vAMD_RADEON_RX6900: s += " AMD RADEON RX6900"; break;
        }

        return s;
    }
};

class PCBuilder {
protected:
    MOTHERBOARD motherboard;
    CPU cpu;
    VIDEOCARD videocard;

public:
    void setMotherboard(MOTHERBOARD motherboard) {
        PCBuilder::motherboard = motherboard;
    }

    void setCpu(CPU cpu) {
        PCBuilder::cpu = cpu;
    }

    void setVideocard(VIDEOCARD videocard) {
        PCBuilder::videocard = videocard;
    }

    virtual PC* build() = 0;
};

class intelGamePCBilder: public PCBuilder {
public:
    virtual PC* build() {
        PC* pc = new PC();

        pc->motherboard = motherboard;
        pc->cpu = CPU::cINTEL_I7;
        pc->videocard = vNVIDIA_RTX_3080;
        return pc;
    }
};

class simplePCBilder: public PCBuilder {
public:
    virtual PC* build() {
        PC* pc = new PC();

        pc->motherboard = motherboard;
        pc->cpu = CPU::cAMD_RYZEN_3;
        return pc;
    }
};

void userGUI(PCBuilder &builder) {

    builder.setMotherboard(MOTHERBOARD::mMSI);
    PC *pc = builder.build();

    cout << "It's your's PC: " << pc->toString() << endl;
}

int main() {
    intelGamePCBilder builder1;
    simplePCBilder builder2;

    userGUI(builder1);
    userGUI(builder2);
}