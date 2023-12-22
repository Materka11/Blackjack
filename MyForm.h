#include <utility>
#include <string>

#pragma once


namespace Blackjack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox_player_1;
	private: System::Windows::Forms::PictureBox^ pictureBox_player_2;
	private: System::Windows::Forms::PictureBox^ pictureBox_dealer_1;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button_start;
	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obsługi projektanta — nie należy modyfikować
		/// jej zawartości w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->pictureBox_player_1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_player_2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_dealer_1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_player_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_player_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_dealer_1))->BeginInit();
			this->SuspendLayout();
			// 
			// button_start
			// 
			this->button_start->BackColor = System::Drawing::SystemColors::Window;
			this->button_start->Location = System::Drawing::Point(426, 260);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(150, 50);
			this->button_start->TabIndex = 0;
			this->button_start->Text = L"START";
			this->button_start->UseVisualStyleBackColor = false;
			this->button_start->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox_player_1
			// 
			this->pictureBox_player_1->Location = System::Drawing::Point(346, 345);
			this->pictureBox_player_1->Name = L"pictureBox_player_1";
			this->pictureBox_player_1->Size = System::Drawing::Size(78, 121);
			this->pictureBox_player_1->TabIndex = 1;
			this->pictureBox_player_1->TabStop = false;
			// 
			// pictureBox_player_2
			// 
			this->pictureBox_player_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_player_2.Image")));
			this->pictureBox_player_2->Location = System::Drawing::Point(510, 345);
			this->pictureBox_player_2->Name = L"pictureBox_player_2";
			this->pictureBox_player_2->Size = System::Drawing::Size(78, 121);
			this->pictureBox_player_2->TabIndex = 2;
			this->pictureBox_player_2->TabStop = false;
			// 
			// pictureBox_dealer_1
			// 
			this->pictureBox_dealer_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_dealer_1.Image")));
			this->pictureBox_dealer_1->Location = System::Drawing::Point(440, 52);
			this->pictureBox_dealer_1->Name = L"pictureBox_dealer_1";
			this->pictureBox_dealer_1->Size = System::Drawing::Size(78, 121);
			this->pictureBox_dealer_1->TabIndex = 3;
			this->pictureBox_dealer_1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 559);
			this->Controls->Add(this->pictureBox_dealer_1);
			this->Controls->Add(this->pictureBox_player_2);
			this->Controls->Add(this->pictureBox_player_1);
			this->Controls->Add(this->button_start);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_player_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_player_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_dealer_1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

			const std::pair<char, std::string> card = { '2', "Kier" };
			char rank = card.first;
			std::string suit = card.second;

			array<String^>^ files = System::IO::Directory::GetFiles(L"skins\\cards\\");



			this->pictureBox_player_1->Image = gcnew Drawing::Bitmap(files[1]);

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
