using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace IT_LAB_3.Models
{
    public class Patient
    {
        [Key]
        public int Id { get; set; }
        [Required]
        public string Name { get; set; }

        [Required]
        [Range(10000, 99999)]
        public int Code { get; set; }
        [Required]
        public string Gender { get; set; }

        public virtual ICollection<Doctor> doctors { get; set; }

        public Patient()
        {
            doctors = new List<Doctor>();
        }
    }
}