#pragma once
#include"frmSeleccionar.h"

namespace pryTrabajoFinalGrupoUno {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmInstrucciones_alternativo
	/// </summary>
	public ref class frmInstrucciones_alternativo : public System::Windows::Forms::Form
	{
	public:
		frmInstrucciones_alternativo(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmInstrucciones_alternativo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnRetMenu;
	protected:
	private: System::Windows::Forms::Button^ btnIniciar;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnRetMenu = (gcnew System::Windows::Forms::Button());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnRetMenu
			// 
			this->btnRetMenu->BackColor = System::Drawing::SystemColors::Desktop;
			this->btnRetMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnRetMenu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRetMenu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRetMenu->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRetMenu->ForeColor = System::Drawing::SystemColors::Control;
			this->btnRetMenu->Location = System::Drawing::Point(297, 750);
			this->btnRetMenu->Name = L"btnRetMenu";
			this->btnRetMenu->Size = System::Drawing::Size(250, 40);
			this->btnRetMenu->TabIndex = 1;
			this->btnRetMenu->Text = L"Volver al menu principal";
			this->btnRetMenu->UseVisualStyleBackColor = false;
			this->btnRetMenu->Click += gcnew System::EventHandler(this, &frmInstrucciones_alternativo::btnRetMenu_Click);
			// 
			// btnIniciar
			// 
			this->btnIniciar->BackColor = System::Drawing::SystemColors::Desktop;
			this->btnIniciar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnIniciar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnIniciar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnIniciar->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnIniciar->Location = System::Drawing::Point(297, 674);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(250, 40);
			this->btnIniciar->TabIndex = 0;
			this->btnIniciar->Text = L"Seleccionar nivel";
			this->btnIniciar->UseVisualStyleBackColor = false;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &frmInstrucciones_alternativo::btnIniciar_Click);
			// 
			// frmInstrucciones_alternativo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(860, 861);
			this->Controls->Add(this->btnRetMenu);
			this->Controls->Add(this->btnIniciar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"frmInstrucciones_alternativo";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Instrucciones";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnRetMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
		frmSeleccionar^ lvlSlc = gcnew frmSeleccionar();
		this->Visible = false;
		lvlSlc->ShowDialog();
	}
	};
}
